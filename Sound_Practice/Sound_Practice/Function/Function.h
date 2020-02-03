#pragma once
#include <cstdint>

namespace okmonn {
	/*�z��̗v�f���̎擾*/
	template <typename T, std::uint32_t size>
	std::uint32_t _countof(const T (&)[size]) {
		return size;
	}
}
