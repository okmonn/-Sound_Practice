#pragma once
#include <cstdint>

struct ADSR;

/*�G���x���[�v�̓�����*/
enum class EV_STATE {
	/*����*/
	done,
	/*�A�^�b�N*/
	attack,
	/*�f�B�P�C*/
	decay,
	/*�T�X�e�B��*/
	sustain,
	/*�����[�X*/
	release,
	/*�G���x���[�v�̓����Ԃ̍ő吔*/
	max
};

struct Envelope {
public:
	/*�R���X�g���N�^*/
	Envelope();
	/*�����Ԃ̐ݒ�
	.ADSR
	.�G���x���[�v�̓���ݒ�
	return �M�������t���O*/
	bool SetState(const ADSR& adsr, const EV_STATE& state);

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
