#pragma once
#include <cstdint>

struct Feedback {
public:
	/*�R���X�g���N�^*/
	Feedback();
	/*�R���X�g���N�^
	���̓��x��*/
	Feedback(const std::uint32_t& gain);
	/*�R�s�[�R���X�g���N�^
	.Feedback*/
	Feedback(const Feedback& fb);
	/*������Z�q
	.Feedback*/
	void operator=(const Feedback& fb);
	/*���̓��x���̐ݒ�
	.���̓��x��(0.0f�`1.0f)*/
	void SetGain(const float& gain);

public:
	/*���̓��x��*/
	std::uint32_t gain;
	/*�t�B�[�h�o�b�N�p�f�[�^*/
	std::int32_t data;
};
