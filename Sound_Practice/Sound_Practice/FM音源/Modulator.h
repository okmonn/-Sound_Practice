#pragma once
#include "Operator/Operator.h"
#include <array>

class Modulator {
public:
	/*�R���X�g���N�^*/
	Modulator();
	/*�R���X�g���N�^
	.�T���v�����O���g��
	.�������g��*/
	Modulator(const std::uint32_t& sample, const std::uint32_t& freq = 440);
	/*�M�������̊J�n*/
	void Start(void);
	/*�M�������̒�~*/
	void Stop(void);
	/*�A���S���Y���̓K�p
	.�K�p�֐��̃|�C���^*/
	void ApplyAlgorithmFunc(std::int32_t(*func)(Modulator*));
	/*�M���̐���
	.�i�[�o�b�t�@
	.�o�b�t�@��*/
	void CreateSignal(std::int16_t* buf, const std::uint32_t& num);
	/*�T���v�����O���g���̐ݒ�
	.�T���v�����O���g��*/
	void SetSample(const std::uint32_t& sample);
	/*�������g���̐ݒ�
	.�������g��*/
	void SetFreq(const std::uint32_t& freq);
	/*�������g���̐ݒ�
	.�������g��*/
	void SetFreq(const float& freq);

public:
	/*�I�y���[�^*/
	std::array<Operator, 4>op;

private:
	/*�T���v�����O���g��*/
	std::uint32_t sample;
	/*�������g��*/
	std::uint32_t freq;
	/*�A���S���Y���̏���*/
	std::int32_t(*algorithm)(Modulator*);
};
