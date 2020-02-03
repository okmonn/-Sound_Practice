#pragma once
#include <cstdint>

/*動作状態*/
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
	release
};

struct Envelope {
public:
	/*コンストラクタ*/
	Envelope();

public:
	/*動作状態*/
	EV_STATE state;
	/*現在の入力レベル*/
	std::uint32_t gain;
	/*入力レベル変化速度*/
	std::int32_t delta;
	/*入力レベル変化カウンタ*/
	std::uint32_t cnt;

private:
	/*動作状態の設定
	.動作状態*/
	void SetState(const EV_STATE& state);
};
