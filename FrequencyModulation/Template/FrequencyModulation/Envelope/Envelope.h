#pragma once
#include <cstdint>

struct ADSR;

/*エンベロープの動作状態*/
enum class EV_STATE {
	/*完了*/
	done,
	/*アタック*/
	attack,
	/*ディケイ*/
	decay,
	/*サスティン*/
	sustain,
	/*リリース*/
	release,
	/*エンベロープの動作状態の最大数*/
	max
};

struct Envelope {
public:
	/*コンストラクタ*/
	Envelope();
	/*動作状態の設定
	.ADSR
	.エンベロープの動作設定
	return 信号生成フラグ*/
	bool SetState(const ADSR& adsr, const EV_STATE& state);

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
