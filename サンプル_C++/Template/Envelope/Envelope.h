#pragma once
#include "../Info.h"
#include <cstdint>

struct Envelope {
public:
	/*�R���X�g���N�^*/
	Envelope();
	/*�f�X�g���N�^*/
	~Envelope();
	/*�����o�̏�����*/
	void Initialize(void);

public:
	/*������*/
	EV_STATE state;
	/*���݂̓��̓��x��*/
	std::uint32_t gain;
	/*���̓��x���ω����x*/
	std::int32_t delta;
	/*���̓��x���ω��J�E���^*/
	std::uint32_t cnt;
};
