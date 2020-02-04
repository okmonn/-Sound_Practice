#include "Parameter.h"
#include <algorithm>

Param::Param()
{
	attackLevel  = 0.0f;
	attack       = 0.0f;
	decay        = 0.0f;
	sustainLevel = 0.0f;
	release      = 0.0f;
	freq_ratio   = 0.0f;
	gain_ratio   = 0.0f;
	fb_gain      = 0.0f;
}

Param::Param(const float& attackLevel, const float& attack, const float& decay, const float& sustainLevel, const float& release, const float& freq_ratio, const float& gain_ratio, const float& fb_gain) : 
	attackLevel(attackLevel), attack(attack), decay(decay), sustainLevel(sustainLevel), release(release), freq_ratio(freq_ratio), gain_ratio(gain_ratio), fb_gain(fb_gain)
{
}

Parameter::Parameter()
{
}

Parameter::Parameter(const std::initializer_list<Param>& param)
{
	this->param.resize(param.size());
	std::copy(param.begin(), param.end(), this->param.begin());
}
