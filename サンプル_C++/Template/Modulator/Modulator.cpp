#include "Modulator.h"
#include "../Operator/Operator.h"
#include "../Function/Function.h"

namespace {
	/*ƒAƒ‹ƒSƒŠƒYƒ€‚²‚Æ‚Ì“ü—ÍƒŒƒxƒ‹”ä—¦*/
	const float gain_ratio[8][OP_MAX] = {
		{ 2.0f , 2.0f , 2.0f , 1.0f  },
		{ 1.0f , 2.0f , 2.0f , 2.0f  },
		{ 1.0f , 2.0f , 2.0f , 2.0f  },
		{ 1.0f , 2.0f , 2.0f , 2.0f  },
		{ 0.5f , 1.0f , 0.5f , 1.0f  },
		{ 0.4f , 0.4f , 0.4f , 2.0f  },
		{ 0.4f , 0.4f , 0.4f , 2.0f  },
		{ 0.25f, 0.25f, 0.25f, 0.25f },
	};
}

Modulator::Modulator() : 
	sample(0), algorithm(0)
{
	for (std::unique_ptr<Operator>& i : op) {
		i = std::make_unique<Operator>();
	}
}

Modulator::Modulator(const std::uint32_t & freq) : 
	sample(freq), algorithm(0)
{
	for (std::unique_ptr<Operator>& i : op) {
		i = std::make_unique<Operator>();
	}
}

Modulator::~Modulator()
{
}

void Modulator::InfluenceParameter(const Parameter & param)
{
	algorithm = param.algorithm;
	std::uint8_t index = 0;
	for (const Param& i : param.info) {
		op[index]->type = i.type;

		op[index]->adsr.SetMember(std::pow(i.gain, 2.0f) * gain_ratio[algorithm][index],
								  std::uint32_t(i.attack * sample),
								  std::uint32_t(i.decay * sample),
								  std::pow(i.sustain, 2.0f) * gain_ratio[algorithm][index],
								  std::uint32_t(i.release *sample));
		op[index]->fb.SetGain(i.fb_gain);
		op[index]->SetRatio(i.ratio);

		++index;
	}
}

template <typename T>
void Modulator::SetCreateFreq(const T & freq)
{
	for (std::unique_ptr<Operator>& i : op) {
		if (i->type == TYPE::variable) {
			i->SetSpeed(((freq << 16) >> 8) * (i->ratio >> 8), sample);
		}
		else {
			i->SetSpeed(i->ratio, sample);
		}
	}
}
template void Modulator::SetCreateFreq(const std::int32_t&);
template void Modulator::SetCreateFreq(const std::uint32_t&);

void Modulator::SetCreateFreq(const float & freq)
{
	for (std::unique_ptr<Operator>& i : op) {
		if (i->type == TYPE::variable) {
			i->SetSpeed(std::uint32_t(freq * 0x100) * (i->ratio >> 8), sample);
		}
		else {
			i->SetSpeed(i->ratio, sample);
		}
	}
}

void Modulator::Start(void)
{
	for (std::unique_ptr<Operator>& i : op) {
		i->Start();
	}
}

void Modulator::Stop(void)
{
	for (std::unique_ptr<Operator>& i : op) {
		i->Stop();
	}
}

void Modulator::CreateSignal(std::int16_t * buf, const std::uint32_t & num)
{
	AlgorithmFunc[algorithm](op, buf, num);
}

void Modulator::SetSampleFreq(const std::uint32_t & freq)
{
	sample = freq;
}
