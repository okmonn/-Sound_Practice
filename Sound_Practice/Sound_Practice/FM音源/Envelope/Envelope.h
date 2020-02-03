#pragma once
#include <cstdint>

/*������*/
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
	release
};

struct Envelope {
public:
	/*�R���X�g���N�^*/
	Envelope();

public:
	/*������*/
	EV_STATE state;
	/*���݂̓��̓��x��*/
	std::uint32_t gain;
	/*���̓��x���ω����x*/
	std::int32_t delta;
	/*���̓��x���ω��J�E���^*/
	std::uint32_t cnt;

private:
	/*�����Ԃ̐ݒ�
	.������*/
	void SetState(const EV_STATE& state);
};
