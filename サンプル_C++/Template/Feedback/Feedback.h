#pragma once
#include <cstdint>

struct Feedback {
public:
	/*�R���X�g���N�^*/
	Feedback();
	/*�f�X�g���N�^*/
	~Feedback();
	/*�t�B�[�h�o�b�N���x���̐ݒ�
	.�t�B�[�h�o�b�N���x��*/
	void SetGain(const float& gain);

public:
	/*�o�̓f�[�^*/
	std::int32_t data;
	/*�t�B�[�h�o�b�N���x��*/
	std::uint32_t gain;
};
