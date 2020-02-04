#include "Function.h"
#include <cassert>
#include <cstdlib>

std::wstring okmonn::ConvertString(const std::string& str)
{
	std::uint32_t num = 0;
	auto hr = mbstowcs_s(&num, nullptr, 0, str.data(), str.size());
	assert(hr == 0);

	std::wstring code;
	code.resize(num);
	hr = mbstowcs_s(nullptr, &code[0], code.size(), str.data(), str.size());
	assert(hr == 0);

	code.pop_back();

	return code;
}

std::string okmonn::ConvertString(const std::wstring& str)
{
	std::uint32_t num = 0;
	auto hr = wcstombs_s(&num, nullptr, 0, str.data(), str.size());
	assert(hr == 0);

	std::string code;
	code.resize(num);
	hr = wcstombs_s(nullptr, &code[0], code.size(), str.data(), str.size());
	assert(hr == 0);

	code.pop_back();

	return code;
}
