#pragma once
#include <string>
#include <cstdint>

namespace okmonn {
	/*string��wstring�ւ̕ϊ�(���P�[���Ɉˑ�)
	.���C�h������
	return ���j�R�[�h������*/
	std::wstring ConvertString(const std::string& str);
	/*wstring��string�ւ̕ϊ�(���P�[���Ɉˑ�)
	.���j�R�[�h������
	return ���C������*/
	std::string ConvertString(const std::wstring& str);
	/*�z��̗v�f���̎擾
	.�z��̃|�C���^*/
	template <typename T, std::uint32_t num>
	std::uint32_t ArrayNum(const T(&)[num]) {
		return num;
	}
}
