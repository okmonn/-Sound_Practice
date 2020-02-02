#pragma once
#include <cstdint>

struct Feedback {
public:
	/*コンストラクタ*/
	Feedback();
	/*コンストラクタ
	入力レベル*/
	Feedback(const std::uint32_t& gain);
	/*コピーコンストラクタ
	.Feedback*/
	Feedback(const Feedback& fb);
	/*代入演算子
	.Feedback*/
	void operator=(const Feedback& fb);
	/*入力レベルの設定
	.入力レベル(0.0f～1.0f)*/
	void SetGain(const float& gain);

public:
	/*入力レベル*/
	std::uint32_t gain;
	/*フィードバック用データ*/
	std::int32_t data;
};
