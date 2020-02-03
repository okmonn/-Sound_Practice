#pragma once
#include <cstdint>

struct ADSR {
public:
	/*コンストラクタ*/
	ADSR();
	/*デストラクタ*/
	~ADSR();
	/*メンバの設定
	.最大入力レベル
	.アタック時間
	.ディケイ時間
	.サスティン時間
	.リリース時間*/
	void SetMember(const float& gain, const std::uint32_t& attack, const std::uint32_t& decay, const float& sustain, const std::uint32_t& release);

public:
	/*最大入力レベル*/
	std::uint32_t gain;
	/*アタック時間*/
	std::uint32_t attack;
	/*ディケイ時間*/
	std::uint32_t decay;
	/*サスティンレベル*/
	std::uint32_t sustain;
	/*リリース時間*/
	std::uint32_t release;
};
