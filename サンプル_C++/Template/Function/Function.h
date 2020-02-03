#pragma once
#include "../Info.h"
#include <array>
#include <memory>
#include <cstdint>
#include <functional>
#include <unordered_map>

struct Operator;

namespace func {
	/*アルゴリズム_0の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_0(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_1の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_1(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_2の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_2(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_3の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_3(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_4の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_4(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_5の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_5(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_6の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_6(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
	/*アルゴリズム_7の処理
	.オペレータのスマートポインタ
	.格納バッファ
	.バッファ数*/
	void Algorithm_7(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t* buf, const std::uint32_t& num);
}

namespace {
	/*アルゴリズムごとの関数ポインタ*/
	std::unordered_map<std::uint8_t, std::function<void(const std::array<std::unique_ptr<Operator>, OP_MAX>&, std::int16_t*, const std::uint32_t&)>>AlgorithmFunc = {
		{ 0, std::bind(&func::Algorithm_0, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 1, std::bind(&func::Algorithm_1, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 2, std::bind(&func::Algorithm_2, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 3, std::bind(&func::Algorithm_3, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 4, std::bind(&func::Algorithm_4, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 5, std::bind(&func::Algorithm_5, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 6, std::bind(&func::Algorithm_6, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
		{ 7, std::bind(&func::Algorithm_7, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) },
	};
}
