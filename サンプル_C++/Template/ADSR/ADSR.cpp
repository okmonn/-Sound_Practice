#include "ADSR.h"

ADSR::ADSR()
{
	gain = sustain = 0xfffffff;
	attack = decay = release = 0;
}

ADSR::~ADSR()
{
}

void ADSR::SetMember(const float & gain, const std::uint32_t & attack, const std::uint32_t & decay, const float & sustain, const std::uint32_t & release)
{
	this->gain    = std::uint32_t(gain * 0xffffffff);
	this->attack  = attack;
	this->decay   = decay;
	this->sustain = std::uint32_t(sustain * 0xffffffff);
	this->release = release;
}
