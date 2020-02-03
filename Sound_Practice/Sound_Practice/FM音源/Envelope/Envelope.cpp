#include "Envelope.h"

Envelope::Envelope()
{
	state = EV_STATE::done;
	gain  = 0;
	delta = 0;
	cnt   = 0;
}
