#pragma once
#include <cstdint>

struct ADSR {
public:
	/*�R���X�g���N�^*/
	ADSR();
	/*�A�^�b�N���̍ő���̓��x���̐ݒ�
	.�A�^�b�N���x��*/
	void SetAttackLevel(const float& level);
	/*�T�X�e�B�����̍ő���̓��x���̐ݒ�
	.�T�X�e�B�����x��*/
	void SetSustainLevel(const float& level);

public:
	/*�A�^�b�N���̍ő���̓��x��*/
	std::uint32_t attackLevel;
	/*�A�^�b�N���̎����T���v����*/
	std::uint32_t attack;
	/*�f�B�P�C���̎����T���v����*/
	std::uint32_t decay;
	/*�T�X�e�B�����̍ő���̓��x��*/
	std::uint32_t sustainLevel;
	/*�����[�X���̎����T���v����*/
	std::uint32_t release;
};
