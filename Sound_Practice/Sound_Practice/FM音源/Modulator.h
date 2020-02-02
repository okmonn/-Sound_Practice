#pragma once
#include "Operator/Operator.h"
#include <array>

class Modulator {
public:
	/*コンストラクタ*/
	Modulator();
	/*コンストラクタ
	.サンプリング周波数
	.生成周波数*/
	Modulator(const std::uint32_t& sample, const std::uint32_t& freq = 440);
	/*信号の生成
	.格納バッファ
	.バッファ数*/
	void CreateSignal(std::int16_t* buf, const std::uint32_t& num);
	/*サンプリング周波数の設定
	.サンプリング周波数*/
	void SetSample(const std::uint32_t& sample);
	/*生成周波数の設定
	.生成周波数*/
	void SetFreq(const std::uint32_t& freq);
	/*生成周波数の設定
	.生成周波数*/
	void SetFreq(const float& freq);

private:
	/*オペレータ*/
	std::array<Operator, 4>op;
	/*サンプリング周波数*/
	std::uint32_t sample;
	/*生成周波数*/
	std::uint32_t freq;
};
