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
	/*信号生成の開始*/
	void Start(void);
	/*信号生成の停止*/
	void Stop(void);
	/*アルゴリズムの適用
	.適用関数のポインタ*/
	void ApplyAlgorithmFunc(std::int32_t(*func)(Modulator*));
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

public:
	/*オペレータ*/
	std::array<Operator, 4>op;

private:
	/*サンプリング周波数*/
	std::uint32_t sample;
	/*生成周波数*/
	std::uint32_t freq;
	/*アルゴリズムの処理*/
	std::int32_t(*algorithm)(Modulator*);
};
