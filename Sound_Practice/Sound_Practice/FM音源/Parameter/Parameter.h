#pragma once
#include <array>

/*オペレータの最大数*/
#define OP_MAX 4

struct Param {
public:
	/*コンストラクタ*/
	Param();

public:
	/*アタック時の最大入力レベル比率*/
	float attackLevel;
	/*アタック時の持続サンプル数比率*/
	float attack;
	/*ディケイ時の持続サンプル数比率*/
	float decay;
	/*サスティン時の最大入力レベル比率*/
	float sustainLevel;
	/*リリース時の持続サンプル数比率*/
	float release;
	/*生成周波数比率*/
	float freq_ratio;
	/*入力レベル比率*/
	float gain_ratio;
	/*フィードバックの入力レベル比率*/
	float fb_gain;
};

struct Parameter {
public:
	/*コンストラクタ*/
	Parameter();
	/*コンストラクタ
	.パラメータのリスト*/
	Parameter(const std::initializer_list<Param>& param);

public:
	/*パラメータ*/
	std::array<Param, OP_MAX>param;
};
