#include "Envelope.h"
#include "../ADSR/ADSR.h"

Envelope::Envelope()
{
	state = EV_STATE::done;
	gain  = 0;
	delta = 0;
	cnt   = 0;
}

bool Envelope::SetState(const ADSR& adsr, const EV_STATE& state)
{
	switch (state)
	{
	case EV_STATE::attack:
		this->state = EV_STATE::attack;
		if (adsr.attack > 0) {
			gain  = 0;
			delta = adsr.attackLevel / adsr.attack;
			cnt   = adsr.attack;
			break;
		}
	case EV_STATE::decay:
		this->state = EV_STATE::decay;
		if (adsr.decay > 0) {
			gain = adsr.attackLevel;
			if (gain > adsr.sustainLevel) {
				delta = -std::int32_t(((gain - adsr.sustainLevel) / adsr.decay));
			}
			else {
				delta = (adsr.sustainLevel - gain) / adsr.decay;
			}
			cnt = adsr.decay;
			break;
		}
	case EV_STATE::sustain:
		this->state = EV_STATE::sustain;
		gain        = adsr.sustainLevel;
		delta       = 0;
		break;
	case EV_STATE::release:
		this->state = EV_STATE::release;
		if (adsr.release > 0) {
			delta = -std::int32_t(gain / adsr.release);
			cnt   = adsr.release;
			break;
		}
	case EV_STATE::done:
	default:
		(*this) = Envelope();
		return false;
	}

	return true;
}
