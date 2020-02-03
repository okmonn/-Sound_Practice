#pragma once
#include "../Parameter/Parameter.h"
#include <memory>

struct Operator;

class Modulator {
public:
	/*�R���X�g���N�^*/
	Modulator();
	/*�R���X�g���N�^
	.�T���v�����O���g��*/
	Modulator(const std::uint32_t& freq);
	/*�f�X�g���N�^*/
	~Modulator();
	/*�p�����[�^�̔��f
	.�p�����[�^*/
	void InfluenceParameter(const Parameter& param);
	/*�������g���̐ݒ�
	.�������g��*/
	template <typename T>
	void SetCreateFreq(const T& freq);
	/*�������g���̐ݒ�
	.�������g��*/
	void SetCreateFreq(const float& freq);
	/*�M�������̊J�n*/
	void Start(void);
	/*�M�������̒�~*/
	void Stop(void);
	/*�M���̐���
	.�i�[�o�b�t�@
	.�o�b�t�@�T�C�Y*/
	void CreateSignal(std::int16_t* buf, const std::uint32_t& num);
	/*�T���v�����O���g���̐ݒ�
	.�T���v�����O���g��*/
	void SetSampleFreq(const std::uint32_t& freq);

private:
	/*�I�y���[�^*/
	std::array<std::unique_ptr<Operator>, OP_MAX>op;
	/*�T���v�����O���g��*/
	std::uint32_t sample;
	/*�A���S���Y��*/
	std::uint8_t algorithm;
};
