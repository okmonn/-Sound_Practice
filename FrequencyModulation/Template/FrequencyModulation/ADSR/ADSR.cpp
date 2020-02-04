#include "ADSR.h"

ADSR::ADSR()
{
	attack  = 0;
	decay   = 0;
	release = 0;
	SetAttackLevel(1.0f);
	SetSustainLevel(1.0f);
}

void ADSR::SetAttackLevel(const float& level)
{
	attackLevel = std::uint32_t(float(0xffffffff) * level)  ;
}

void ADSR::SetSustainLevel(const float& level)
{
	sustainLevel = std::uint32_t(float(0xffffffff) * level);
}
