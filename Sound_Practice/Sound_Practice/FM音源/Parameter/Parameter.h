#pragma once
#include <array>

/*�I�y���[�^�̍ő吔*/
#define OP_MAX 4

struct Param {
public:
	/*�R���X�g���N�^*/
	Param();

public:
	/*�A�^�b�N���̍ő���̓��x���䗦*/
	float attackLevel;
	/*�A�^�b�N���̎����T���v�����䗦*/
	float attack;
	/*�f�B�P�C���̎����T���v�����䗦*/
	float decay;
	/*�T�X�e�B�����̍ő���̓��x���䗦*/
	float sustainLevel;
	/*�����[�X���̎����T���v�����䗦*/
	float release;
	/*�������g���䗦*/
	float freq_ratio;
	/*���̓��x���䗦*/
	float gain_ratio;
	/*�t�B�[�h�o�b�N�̓��̓��x���䗦*/
	float fb_gain;
};

struct Parameter {
public:
	/*�R���X�g���N�^*/
	Parameter();
	/*�R���X�g���N�^
	.�p�����[�^�̃��X�g*/
	Parameter(const std::initializer_list<Param>& param);

public:
	/*�p�����[�^*/
	std::array<Param, OP_MAX>param;
};
