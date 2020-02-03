#include "Parameter.h"

Parameter::Parameter()
{
	algorithm = 0;
}

Parameter::Parameter(const std::uint8_t & algorithm, const std::initializer_list<Param>& param) : 
	algorithm(algorithm)
{
	std::uint8_t index = 0;
	for (const Param& i : param) {
		info[index++] = i;
	}
}

Parameter::~Parameter()
{
}
