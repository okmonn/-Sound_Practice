#pragma once
#include <array>

/*オペレータの最大数*/
#define OP_MAX 4

struct Param {
public:
	/*コンストラクタ*/
	Param();
	/*コンストラクタ
	.アタック時の最大入力レベル比率
	.アタック時の持続サンプル数比率
	.ディケイ時の持続サンプル数比率
	.サスティン時の最大入力レベル比率
	.リリース時の持続サンプル数比率
	.生成周波数比率
	.入力レベル比率
	.フィードバック用入力レベル比率*/
	Param(const float& attackLevel, const float& attack, const float& decay, const float& sustainLevel,
		const float& release, const float& freq_ratio, const float& gain_ratio, const float& fb_gain);

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
