#pragma once
#include "../Feedback/Feedback.h"
#include "../ADSR/ADSR.h"
#include "../Envelope/Envelope.h"

struct Operator {
public:
	/*コンストラクタ*/
	Operator();
	/*信号生成の開始*/
	void Start(void);
	/*信号生成の停止*/
	void Stop(void);
	/*信号の生成(モジュレータなし、フィードバックなし)
	return 信号*/
	std::int32_t CreateSignalSimple(void);
	/*信号の生成(モジュレータなし、フィードバックあり)
	return 信号*/
	std::int32_t CreateSignalFB(void);
	/*信号の生成(モジュレータあり、フィードバックなし)
	.モジュレータ用の信号
	return 信号*/
	std::int32_t CreateSignalModulation(const std::int32_t& mod);
	/*読み出し速度の設定
	.生成信号
	.サンプリング周波数*/
	void SetSpeed(const std::uint32_t& freq, const std::uint32_t& sample);
	/*生成周波数比率の設定
	.周波数比率(0.0f～1.0f)*/
	void SetRatio(const float& ratio);

public:
	/*エンベロープ*/
	Envelope ev;
	/*ADSR*/
	ADSR adsr;
	/*フィードバック*/
	Feedback fb;
	/*読み出し位置*/
	std::uint32_t pos;
	/*読み出し速度*/
	std::uint32_t speed;
	/*生成周波数比率*/
	std::uint32_t ratio;
	/*信号生成フラグ*/
	bool flag;
	
private:
	/*エンベロープの制御
	return 出力レベル比率*/
	std::int32_t EnvelopeControler(void);
};
