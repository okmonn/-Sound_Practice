#include "Envelope.h"

Envelope::Envelope()
{
	Initialize();
}

Envelope::~Envelope()
{
}

void Envelope::Initialize(void)
{
	state = EV_STATE::start;
	gain = delta = cnt = 0;
}
