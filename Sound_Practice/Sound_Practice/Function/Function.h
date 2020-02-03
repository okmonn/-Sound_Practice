#pragma once
#include <cstdint>

namespace okmonn {
	/*”z—ñ‚Ì—v‘f”‚Ìæ“¾*/
	template <typename T, std::uint32_t size>
	std::uint32_t _countof(const T (&)[size]) {
		return size;
	}
}
