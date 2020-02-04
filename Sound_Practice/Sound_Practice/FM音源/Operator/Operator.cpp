#include "Operator.h"
#include "../SinTbl.h"

Operator::Operator()
{
	pos   = 0;
	speed = 0;
	ratio = 0x10000;
	flag  = false;
}

void Operator::Start(void)
{
	ev      = Envelope();
	flag    = ev.SetState(adsr, EV_STATE((std::uint32_t(ev.state) + 1) % std::uint32_t(EV_STATE::max)));
	fb.data = 0;
}

void Operator::Stop(void)
{
	if (flag == true) {
		if (ev.state != EV_STATE::release) {
			flag = ev.SetState(adsr, EV_STATE::release);
		}
	}
}

std::int32_t Operator::EnvelopeControler(void)
{
	if (ev.cnt == 0 && ev.state != EV_STATE::sustain) {
		flag = ev.SetState(adsr, EV_STATE((std::uint32_t(ev.state) + 1) % std::uint32_t(EV_STATE::max)));
	}
	
	std::int32_t gain = (ev.gain >> 16);
 	ev.gain += ev.delta;
	--ev.cnt;

	return gain;
}

std::int32_t Operator::CreateSignalSimple(void)
{
	if (flag == false) {
		return 0;
	}

	std::int32_t signal = sinTbl[(pos >> 20)] * EnvelopeControler();
	pos += speed;

	return signal;
}

std::int32_t Operator::CreateSignalFB(void)
{
	if (flag == false) {
		return 0;
	}

	std::int32_t signal = sinTbl[(pos + (fb.data * fb.gain)) >> 20];
	fb.data = (sinTbl[pos >> 20] >> 12);
	pos += speed;

	return signal;
}

std::int32_t Operator::CreateSignalModulation(const std::int32_t& mod)
{
	if (flag == false) {
		return 0;
	}

	std::int32_t signal = sinTbl[((pos + mod) >> 20)];
	pos += speed;

	return signal;
}

void Operator::SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample)
{
	speed = (freq / sample) << 16;
}

void Operator::SetRatio(const float& ratio)
{
	this->ratio = std::uint32_t(ratio * float(0x10000));
}
