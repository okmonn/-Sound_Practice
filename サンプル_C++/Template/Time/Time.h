#pragma once
#include <cstdint>

class Time {
public:
	/*�R���X�g���N�^*/
	Time();
	/*�f�X�g���N�^*/
	~Time();
	/*�v���̊J�n*/
	void Begin(void);
	/*�v���̏I��
	return �v������(�i�m�b)*/
	std::uint64_t End(void);
	/*�v�����ʂ̎擾
	return �v������*/
	std::uint64_t GetResult(void) const;

private:
	/*�J�n����*/
	std::uint64_t begin;
	/*�I������*/
	std::uint64_t end;
	/*�v������*/
	std::uint64_t result;
};
