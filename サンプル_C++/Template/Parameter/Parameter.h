#pragma once
#include "../Info.h"
#include <array>
#include <cstdint>

struct Param {
public:
	/*コンストラクタ*/
	Param() {
		type = TYPE::variable;
		gain = sustain = fb_gain = 1.0f;
		attack = decay = release = ratio = 1.0f;
	}
	/*コンストラクタ*/
	Param(const float& gain, const float& attack, const float& decay, const float& sustain, const float& release, const TYPE& type, const float& ratio, const float& fb_gain) : 
		gain(gain), attack(attack), decay(decay), sustain(sustain), release(release), type(type), ratio(ratio), fb_gain(fb_gain) {}
	/*デストラクタ*/
	~Param() {}

public:
	/*最大入力レベル*/
	float gain;
	/*アタック時間*/
	float attack;
	/*ディケイ時間*/
	float decay;
	/*サスティンレベル*/
	float sustain;
	/*リリース時間*/
	float release;
	/*オペレータの周波数タイプ*/
	TYPE type;
	/*生成周波数比率*/
	float ratio;
	/*フィードバックレベル*/
	float fb_gain;
};

struct Parameter {
public:
	/*コンストラクタ*/
	Parameter();
	/*コンストラクタ
	.アルゴリズム
	.パラメータ(最大数：OP_MAX)*/
	Parameter(const std::uint8_t& algorithm, const std::initializer_list<Param>& param);
	/*デストラクタ*/
	~Parameter();

public:
	/*アルゴリズム*/
	std::uint8_t algorithm;
	/*パラメータ*/
	std::array<Param, OP_MAX>info;
};

namespace {
	/*プリセット*/
	const Parameter preset[] = {
		{/*SYN_BASS*/
			2,
			{{0.9f , 0.0f, 1.0f, 0.85f, 0.5f, TYPE::variable, 0.5f, 0.0f },
			{ 0.8f , 0.0f, 1.5f, 0.2f , 0.5f, TYPE::variable, 0.5f, 0.0f },
			{ 0.25f, 0.2f, 1.3f, 0.7f , 0.3f, TYPE::variable, 2.0f, 0.0f },
			{ 0.9f , 0.0f, 0.6f, 0.2f , 0.5f, TYPE::variable, 0.5f, 0.57f}},
		},
		{/*BELL*/
			4,
			{{0.9f , 0.0f, 6.0f, 0.15f, 0.5f, TYPE::variable, 1.0f, 0.0f },
			{ 0.5f , 0.0f, 6.0f, 0.1f , 0.5f, TYPE::variable, 3.5f, 0.0f },
			{ 0.85f, 0.0f, 6.3f, 0.4f , 0.5f, TYPE::variable, 1.0f, 0.0f },
			{ 0.7f , 0.0f, 6.0f, 0.1f , 0.5f, TYPE::variable, 3.5f, 0.01f}},
		},
		{/*DX PIANO*/
			4,
			{{0.9f , 0.0f , 6.0f, 0.2f , 0.5f, TYPE::variable, 1.0f, 0.0f },
			{ 0.8f , 0.0f , 0.3f, 0.01f, 0.5f, TYPE::variable, 1.0f, 0.0f },
			{ 0.85f, 0.15f, 3.5f, 0.3f , 1.0f, TYPE::variable, 1.0f, 0.0f },
			{ 0.5f , 0.0f , 1.0f, 0.3f , 0.8f, TYPE::variable, 2.0f, 0.15f}},
		},
		{/*SYN BRASS*/
			0,
			{{0.9f , 0.1f, 0.2f, 0.7f , 1.0f, TYPE::variable, 1.0f, 0.0f },
			{ 0.25f, 0.0f, 0.5f, 0.7f , 0.5f, TYPE::variable, 1.0f, 0.0f },
			{ 0.75f, 0.1f, 0.5f, 0.5f , 0.5f, TYPE::variable, 0.5f, 0.0f },
			{ 0.4f , 0.0f, 0.4f, 0.05f, 0.5f, TYPE::variable, 3.0f, 0.28f}},
		},
		{/*PIPE ORGAN*/
			7,
			{{1.0f, 0.05f, 0.25f, 1.0f, 0.5f, TYPE::variable, 0.5f, 0.0f },
			{ 1.0f, 0.1f , 0.25f, 1.0f, 0.8f, TYPE::variable, 2.0f, 0.0f },
			{ 0.9f, 0.1f , 0.15f, 1.0f, 1.2f, TYPE::variable, 1.0f, 0.0f },
			{ 0.3f, 0.4f , 0.1f , 0.4f, 1.2f, TYPE::variable, 4.0f, 1.0f }},
		}
	};
}
