#include "Operator.h"
#include "../SinTbl.h"

Operator::Operator() : 
	state(STATE::stop), type(TYPE::variable)
{
	pos = speed = ratio = 0;
}

Operator::~Operator()
{
}

void Operator::Start(void)
{
	state   = STATE::execute;
	fb.data = 0;
	ev.Initialize();
}

void Operator::Stop(void)
{
	if (state == STATE::execute) {
		if (ev.state != EV_STATE::release) {
			ev.state = EV_STATE::note_off;
			ev.cnt   = 0;
		}
	}
	else {
		state = STATE::stop;
	}
}

std::int32_t Operator::EnvelopeControler(void)
{
	if (ev.cnt == 0) {
		switch (ev.state)
		{
		case EV_STATE::start:
			ev.state = EV_STATE::attack;
			if (adsr.attack > 0) {
				ev.delta = std::int32_t(adsr.gain / adsr.attack);
				ev.cnt   = adsr.attack;
				break;
			}
		case EV_STATE::attack:
			ev.state = EV_STATE::decay;
			if (adsr.decay > 0) {
				ev.gain = adsr.gain;
				if (adsr.gain > adsr.sustain) {
					ev.delta = -std::int32_t((ev.gain - adsr.sustain) / adsr.decay);
				}
				else {
					ev.delta = std::int32_t((adsr.sustain - ev.gain) / adsr.decay);
				}
				ev.cnt = adsr.decay;
				break;
			}
		case EV_STATE::decay:
			ev.state = EV_STATE::sustain;
			ev.gain  = adsr.sustain;
			ev.delta = ev.cnt = 0;
			break;
		case EV_STATE::sustain:
			break;
		case EV_STATE::note_off:
			ev.state = EV_STATE::release;
			if (adsr.release > 0) {
				ev.delta = -std::int32_t(ev.gain / adsr.release);
				ev.cnt   = adsr.release;
				break;
			}
		case EV_STATE::release:
			state    = STATE::stop;
			break;
		default:
			break;
		}
	}

	std::int32_t gain = (ev.gain >> 16);
	ev.gain += ev.delta;
	--ev.cnt;

	return gain;
}

std::int32_t Operator::CreateSignalSimple(void)
{
	if (state != STATE::execute) {
		return 0;
	}

	std::int32_t signal = sinTbl[(pos >> 20)] * EnvelopeControler();
	pos += speed;

	return signal;
}

std::int32_t Operator::CreateSignalFB(void)
{
	if (state != STATE::execute) {
		return 0;
	}

	std::int32_t gain   = EnvelopeControler();
	std::int32_t signal = sinTbl[((pos + (fb.gain * fb.data)) >> 20)] * gain;
	fb.data = ((sinTbl[(pos >> 20)] * gain) >> 12);
	pos += speed;

	return signal;
}

std::int32_t Operator::CreateSignalModulation(const std::int32_t & mod)
{
	if (state != STATE::execute) {
		return 0;
	}
 
	std::int32_t signal = sinTbl[((pos + mod) >> 20)] * EnvelopeControler();
	pos += speed;

	return signal;
}

void Operator::SetSpeed(const std::uint32_t & freq, const std::uint32_t & sample)
{
	speed = ((freq / sample) << 16);
}

void Operator::SetRatio(const float & ratio)
{
	this->ratio = std::uint32_t(ratio * 0x10000);
}
