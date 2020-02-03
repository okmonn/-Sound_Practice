#include "Feedback.h"
#include "../SinTbl.h"

Feedback::Feedback()
{
	data = gain = 0;
}

Feedback::~Feedback()
{
}

void Feedback::SetGain(const float & gain)
{
	/*�T�C���g��`��1/4�����Ȃ̂�1�����̃T�C�Y�Ōv�Z*/
	this->gain = std::uint32_t(gain * sinTbl.size() * 4.0f);
}
