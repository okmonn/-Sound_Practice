#pragma once
#include "../Feedback/Feedback.h"
#include "../ADSR/ADSR.h"
#include "../Envelope/Envelope.h"

class Modulator;

struct Operator {
	friend Modulator;
public:
	/*�R���X�g���N�^*/
	Operator();
	/*�M���̐���(���W�����[�^�Ȃ��A�t�B�[�h�o�b�N�Ȃ�)
	return �M��*/
	std::int32_t CreateSignalSimple(void);
	/*�M���̐���(���W�����[�^�Ȃ��A�t�B�[�h�o�b�N����)
	return �M��*/
	std::int32_t CreateSignalFB(void);
	/*�M���̐���(���W�����[�^����A�t�B�[�h�o�b�N�Ȃ�)
	.���W�����[�^�p�̐M��
	return �M��*/
	std::int32_t CreateSignalModulation(const std::int32_t& mod);

private:
	/*�M�������̊J�n*/
	void Start(void);
	/*�M�������̒�~*/
	void Stop(void);
	/*�G���x���[�v�̐���
	return �o�̓��x���䗦*/
	std::int32_t EnvelopeControler(void);
	/*�ǂݏo�����x�̐ݒ�
	.�����M��
	.�T���v�����O���g��*/
	void SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample);
	/*�������g���䗦�̐ݒ�
	.���g���䗦(0.0f�`1.0f)*/
	void SetRatio(const float& ratio);

	/*�G���x���[�v*/
	Envelope ev;
	/*ADSR*/
	ADSR adsr;
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
