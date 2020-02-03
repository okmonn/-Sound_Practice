#pragma once
#include "../Parameter/Parameter.h"
#include <memory>

struct Operator;

class Modulator {
public:
	/*コンストラクタ*/
	Modulator();
	/*コンストラクタ
	.サンプリング周波数*/
	Modulator(const std::uint32_t& freq);
	/*デストラクタ*/
	~Modulator();
	/*パラメータの反映
	.パラメータ*/
	void InfluenceParameter(const Parameter& param);
	/*生成周波数の設定
	.生成周波数*/
	template <typename T>
	void SetCreateFreq(const T& freq);
	/*生成周波数の設定
	.生成周波数*/
	void SetCreateFreq(const float& freq);
	/*信号生成の開始*/
	void Start(void);
	/*信号生成の停止*/
	void Stop(void);
	/*信号の生成
	.格納バッファ
	.バッファサイズ*/
	void CreateSignal(std::int16_t* buf, const std::uint32_t& num);
	/*サンプリング周波数の設定
	.サンプリング周波数*/
	void SetSampleFreq(const std::uint32_t& freq);

private:
	/*オペレータ*/
	std::array<std::unique_ptr<Operator>, OP_MAX>op;
	/*サンプリング周波数*/
	std::uint32_t sample;
	/*アルゴリズム*/
	std::uint8_t algorithm;
};
