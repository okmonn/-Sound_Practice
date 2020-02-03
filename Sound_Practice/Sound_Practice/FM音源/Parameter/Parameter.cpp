#include "Parameter.h"

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

Parameter::Parameter()
{
}

Parameter::Parameter(const std::initializer_list<Param>& param)
{
	std::uint32_t index = 0;
	for (auto& i : param) {
		this->param[index++] = i;
	}
}
