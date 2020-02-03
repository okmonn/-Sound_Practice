#include "Modulator.h"

Modulator::Modulator()
{
	sample    = 0;
	freq      = 0;
	ApplyAlgorithmFunc([](Modulator* mod)->std::int32_t {
		return mod->op[0].CreateSignalSimple();
	});
}

Modulator::Modulator(const std::uint32_t& sample, const std::uint32_t& freq)
{
	SetSample(sample);
	SetFreq(freq);
	ApplyAlgorithmFunc([](Modulator* mod)->std::int32_t {
		return mod->op[0].CreateSignalSimple();
	});
}

void Modulator::Start(void)
{
	for (auto& i : op) {
		i.Start();
	}
}

void Modulator::Stop(void)
{
	for (auto& i : op) {
		i.Stop();
	}
}

void Modulator::ApplyAlgorithmFunc(std::int32_t(*func)(Modulator*))
{
	this->algorithm = func;
}

void Modulator::CreateSignal(std::int16_t* buf, const std::uint32_t& num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		buf[i] = algorithm(this);
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
