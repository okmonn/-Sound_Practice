#pragma once
#include <cstdint>

struct Feedback {
public:
	/*コンストラクタ*/
	Feedback();
	/*デストラクタ*/
	~Feedback();
	/*フィードバックレベルの設定
	.フィードバックレベル*/
	void SetGain(const float& gain);

public:
	/*出力データ*/
	std::int32_t data;
	/*フィードバックレベル*/
	std::uint32_t gain;
};
