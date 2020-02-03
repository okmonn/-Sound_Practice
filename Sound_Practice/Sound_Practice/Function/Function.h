#pragma once
#include <cstdint>

namespace okmonn {
	/*配列の要素数の取得*/
	template <typename T, std::uint32_t size>
	std::uint32_t _countof(const T (&)[size]) {
		return size;
	}
}
