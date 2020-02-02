#include "Operator.h"
#include "../SinTbl.h"

Operator::Operator()
{
	pos   = 0;
	speed = 0;
	ratio = 0x10000;
	flag  = false;
}

Operator::Operator(const Operator& op)
{
	(*this) = op;
}

void Operator::operator=(const Operator& op)
{
	fb.gain = op.fb.gain;
	pos     = 0;
	speed   = op.speed;
	ratio   = op.ratio;
	flag    = false;
}

void Operator::Start(void)
{
	if (flag == false) {
		flag = true;
	}
}

void Operator::Stop(void)
{
	if (flag == true) {
		flag = false;
	}
}

std::int32_t Operator::CreateSignal(void)
{
	if (flag == false) {
		return 0;
	}

	std::int32_t signal = sinTbl[pos >> 20];
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
