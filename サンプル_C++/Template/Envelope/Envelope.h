#pragma once
#include "../Info.h"
#include <cstdint>

struct Envelope {
public:
	/*コンストラクタ*/
	Envelope();
	/*デストラクタ*/
	~Envelope();
	/*メンバの初期化*/
	void Initialize(void);

public:
	/*動作状態*/
	EV_STATE state;
	/*現在の入力レベル*/
	std::uint32_t gain;
	/*入力レベル変化速度*/
	std::int32_t delta;
	/*入力レベル変化カウンタ*/
	std::uint32_t cnt;
};
