#pragma once
#include "../Envelope/Envelope.h"
#include "../ADSR/ADSR.h"
#include "../Feedback/Feedback.h"

struct Operator {
public:
	/*コンストラクタ*/
	Operator();
	/*デストラクタ*/
	~Operator();
	/*開始*/
	void Start(void);
	/*停止*/
	void Stop(void);
	/*エンベロープの制御
	return 現在の入力レベル*/
	std::int32_t EnvelopeControler(void);
	/*信号の生成(モジュレーションなし、フィードバックなし)
	return 信号*/
	std::int32_t CreateSignalSimple(void);
	/*信号の生成(モジュレーションなし、フィードバックあり)
	return 信号*/
	std::int32_t CreateSignalFB(void);
	/*信号の生成(モジュレーションあり、フィードバックなし)
	.モジュレータ*/
	std::int32_t CreateSignalModulation(const std::int32_t& mod);
	/*読み出し速度の設定
	.生成周波数
	.サンプリング周波数*/
	void SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample);
	/*生成周波数比率の設定
	.周波数比率*/
	void SetRatio(const float& ratio);

public:
	/*エンベロープ*/
	Envelope ev;
	/*ADSR*/
	ADSR adsr;
	/*フィードバック*/
	Feedback fb;
	/*動作状態*/
	STATE state;
	/*周波数タイプ*/
	TYPE type;
	/*読み出し位置*/
	std::uint32_t pos;
	/*読み出し速度*/
	std::uint32_t speed;
	/*生成周波数比率*/
	std::uint32_t ratio;
};
