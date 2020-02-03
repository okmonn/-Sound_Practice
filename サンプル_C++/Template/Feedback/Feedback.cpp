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
	/*サイン波定義は1/4周分なので1周分のサイズで計算*/
	this->gain = std::uint32_t(gain * sinTbl.size() * 4.0f);
}
