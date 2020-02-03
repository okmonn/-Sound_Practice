#pragma once
#include "../Envelope/Envelope.h"
#include "../ADSR/ADSR.h"
#include "../Feedback/Feedback.h"

struct Operator {
public:
	/*�R���X�g���N�^*/
	Operator();
	/*�f�X�g���N�^*/
	~Operator();
	/*�J�n*/
	void Start(void);
	/*��~*/
	void Stop(void);
	/*�G���x���[�v�̐���
	return ���݂̓��̓��x��*/
	std::int32_t EnvelopeControler(void);
	/*�M���̐���(���W�����[�V�����Ȃ��A�t�B�[�h�o�b�N�Ȃ�)
	return �M��*/
	std::int32_t CreateSignalSimple(void);
	/*�M���̐���(���W�����[�V�����Ȃ��A�t�B�[�h�o�b�N����)
	return �M��*/
	std::int32_t CreateSignalFB(void);
	/*�M���̐���(���W�����[�V��������A�t�B�[�h�o�b�N�Ȃ�)
	.���W�����[�^*/
	std::int32_t CreateSignalModulation(const std::int32_t& mod);
	/*�ǂݏo�����x�̐ݒ�
	.�������g��
	.�T���v�����O���g��*/
	void SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample);
	/*�������g���䗦�̐ݒ�
	.���g���䗦*/
	void SetRatio(const float& ratio);

public:
	/*�G���x���[�v*/
	Envelope ev;
	/*ADSR*/
	ADSR adsr;
	/*�t�B�[�h�o�b�N*/
	Feedback fb;
	/*������*/
	STATE state;
	/*���g���^�C�v*/
	TYPE type;
	/*�ǂݏo���ʒu*/
	std::uint32_t pos;
	/*�ǂݏo�����x*/
	std::uint32_t speed;
	/*�������g���䗦*/
	std::uint32_t ratio;
};
