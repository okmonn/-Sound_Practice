#pragma once
#include <cstdint>

struct ADSR {
public:
	/*�R���X�g���N�^*/
	ADSR();
	/*�f�X�g���N�^*/
	~ADSR();
	/*�����o�̐ݒ�
	.�ő���̓��x��
	.�A�^�b�N����
	.�f�B�P�C����
	.�T�X�e�B������
	.�����[�X����*/
	void SetMember(const float& gain, const std::uint32_t& attack, const std::uint32_t& decay, const float& sustain, const std::uint32_t& release);

public:
	/*�ő���̓��x��*/
	std::uint32_t gain;
	/*�A�^�b�N����*/
	std::uint32_t attack;
	/*�f�B�P�C����*/
	std::uint32_t decay;
	/*�T�X�e�B�����x��*/
	std::uint32_t sustain;
	/*�����[�X����*/
	std::uint32_t release;
};
