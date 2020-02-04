#include "XAudio2/XAudio.h"
#include <cmath>
#include <cassert>
#include <combaseapi.h>

namespace {
	/*サンプリング周波数*/
	const std::uint32_t sample = 48000;
	/*量子化ビット数*/
	const std::uint8_t bit     = 16;
	/*チャンネル数*/
	const std::uint8_t channel = 1;
}

/*エントリーポイント*/
int main() {
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(hr == S_OK);

	XAudio* engine = nullptr;
	hr = CreateXAudio(&engine);
	assert(hr == S_OK);

	SourceVoice voice(engine, sample, bit, channel);

	std::int16_t buf[sample];
	for (std::uint32_t i = 0; i < sample; ++i) {
		buf[i] = 0x7fff * std::sin(2.0f * std::acos(-1.0f) * 440.0f * i / sample);
	}
	voice.Play(buf, sample);

	Release(&engine);
	return 0;
}