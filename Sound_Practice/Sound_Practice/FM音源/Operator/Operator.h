#pragma once
#include "../Feedback/Feedback.h"

struct Operator {
public:
	/*�R���X�g���N�^*/
	Operator();
	/*�R�s�[�R���X�g���N�^
	.Operator*/
	Operator(const Operator& op);
	/*������Z�q
	.Operator*/
	void operator=(const Operator& op);
	/*�M�������̊J�n*/
	void Start(void);
	/*�M�������̒�~*/
	void Stop(void);
	/*�M���̐���(���W�����[�^�Ȃ��A�t�B�[�h�o�b�N�Ȃ�)
	return �M��*/
	std::int32_t CreateSignalSimple(void);
	/*�ǂݏo�����x�̐ݒ�
	.�����M��
	.�T���v�����O���g��*/
	void SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample);
	/*�������g���䗦�̐ݒ�
	.���g���䗦(0.0f�`1.0f)*/
	void SetRatio(const float& ratio);

public:
	/*�t�B�[�h�o�b�N*/
	Feedback fb;
	/*�ǂݏo���ʒu*/
	std::uint32_t pos;
	/*�ǂݏo�����x*/
	std::uint32_t speed;
	/*�������g���䗦*/
	std::uint32_t ratio;
	/*�M�������t���O*/
	bool flag;
};
