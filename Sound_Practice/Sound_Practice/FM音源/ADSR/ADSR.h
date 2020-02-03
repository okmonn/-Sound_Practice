#pragma once
#include <cstdint>

struct ADSR {
public:
	/*コンストラクタ*/
	ADSR();
	/*アタック時の最大入力レベルの設定
	.アタックレベル*/
	void SetAttackLevel(const float& level);
	/*サスティン時の最大入力レベルの設定
	.サスティンレベル*/
	void SetSustainLevel(const float& level);

public:
	/*アタック時の最大入力レベル*/
	std::uint32_t attackLevel;
	/*アタック時の持続サンプル数*/
	std::uint32_t attack;
	/*ディケイ時の持続サンプル数*/
	std::uint32_t decay;
	/*サスティン時の最大入力レベル*/
	std::uint32_t sustainLevel;
	/*リリース時の持続サンプル数*/
	std::uint32_t release;
};
