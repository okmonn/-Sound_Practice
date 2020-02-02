#include "Modulator.h"

Modulator::Modulator()
{
	sample = 0;
	freq   = 0;
}

Modulator::Modulator(const std::uint32_t& sample, const std::uint32_t& freq)
{
	SetSample(sample);
	SetFreq(freq);
}

void Modulator::CreateSignal(std::int16_t* buf, const std::uint32_t& num)
{
	for (std::uint32_t i = 0; i < op.size(); ++i) {
		buf[i] = op[0].CreateSignal();
	}
}

void Modulator::SetSample(const std::uint32_t& sample)
{
	this->sample = sample;
}

void Modulator::SetFreq(const std::uint32_t& freq)
{
	this->freq = freq << 16;
	for (auto& i : op) {
		i.SetSpeed((this->freq >> 8)* (i.ratio >> 8), sample);
	}
}

void Modulator::SetFreq(const float& freq)
{
	this->freq = std::uint32_t(freq * float(0x10000));
	for (auto& i : op) {
		i.SetSpeed((this->freq >> 8)* (i.ratio >> 8), sample);
	}
}
