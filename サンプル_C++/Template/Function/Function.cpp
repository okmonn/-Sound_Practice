#include "Function.h"
#include "../Operator/Operator.h"

/*クリッピング*/
std::int16_t Clipping(const std::int32_t& buf) {
	std::int32_t tmp = buf >> 16;
	if (tmp >= 0x7fff) {
		return 0x7fff;
	}
	else if (tmp <= -0x7fff) {
		return -0x7fff;
	}

	return std::int16_t(tmp);
}

void func::Algorithm_0(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t tmp = op[3]->CreateSignalFB();
		tmp = op[2]->CreateSignalModulation(tmp);
		tmp = op[1]->CreateSignalModulation(tmp);
		tmp = op[0]->CreateSignalModulation(tmp);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_1(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t pcm = op[3]->CreateSignalFB();
		std::int32_t tmp = op[2]->CreateSignalSimple();
		tmp = op[1]->CreateSignalModulation(tmp + pcm);
		tmp = op[0]->CreateSignalModulation(tmp);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_2(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t pcm = op[3]->CreateSignalFB();
		std::int32_t tmp = op[2]->CreateSignalSimple();
		tmp = op[1]->CreateSignalModulation(tmp);
		tmp = op[0]->CreateSignalModulation(tmp + pcm);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_3(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t tmp = op[3]->CreateSignalFB();
		tmp = op[2]->CreateSignalModulation(tmp);
		std::int32_t pcm = op[1]->CreateSignalSimple();
		tmp = op[0]->CreateSignalModulation(tmp + pcm);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_4(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t tmp = op[3]->CreateSignalFB();
		tmp = op[2]->CreateSignalModulation(tmp);
		std::int32_t pcm = op[1]->CreateSignalSimple();
		tmp += op[0]->CreateSignalModulation(pcm);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_5(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t pcm = op[3]->CreateSignalFB();
		std::int32_t tmp = op[2]->CreateSignalModulation(pcm);
		tmp += op[1]->CreateSignalModulation(pcm);
		tmp += op[0]->CreateSignalModulation(pcm);

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_6(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t tmp = op[3]->CreateSignalFB();
		tmp = op[2]->CreateSignalModulation(tmp);
		tmp += op[1]->CreateSignalSimple();
		tmp += op[0]->CreateSignalSimple();

		buf[i] = Clipping(tmp);
	}
}

void func::Algorithm_7(const std::array<std::unique_ptr<Operator>, OP_MAX>& op, std::int16_t * buf, const std::uint32_t & num)
{
	for (std::uint32_t i = 0; i < num; ++i) {
		std::int32_t tmp = op[3]->CreateSignalFB();
		tmp += op[2]->CreateSignalSimple();
		tmp += op[1]->CreateSignalSimple();
		tmp += op[0]->CreateSignalSimple();

		buf[i] = Clipping(tmp);
	}
}
