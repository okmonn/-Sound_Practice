#pragma once
#include <string>
#include <cstdint>

namespace okmonn {
	/*string⇒wstringへの変換(ロケールに依存)
	.ワイド文字列
	return ユニコード文字列*/
	std::wstring ConvertString(const std::string& str);
	/*wstring⇒stringへの変換(ロケールに依存)
	.ユニコード文字列
	return ワイ文字列*/
	std::string ConvertString(const std::wstring& str);
	/*配列の要素数の取得
	.配列のポインタ*/
	template <typename T, std::uint32_t num>
	std::uint32_t ArrayNum(const T(&)[num]) {
		return num;
	}
}
