#include <cassert>
#include <Windows.h>

#include <XAudio.h>
#include <Modulator.h>

#pragma comment(lib, "XAudio2.lib")
#pragma comment(lib, "FrequencyModulation.lib")

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

	Modulator mod(sample);

	std::int16_t buf[sample / 100];
	bool key = false;
	while (!(GetKeyState(VK_ESCAPE) & 0x80)) {
		if (GetKeyState(VK_SPACE) & 0x80) {
			if (key == false) {
				key = true;
				mod.SetFreq(261U);
				mod.Start();
			}
		}
		else {
			if (key == true) {
				key = false;
				mod.Stop();
			}
		}

		mod.CreateSignal(buf, _countof(buf));
		voice.Play(buf, _countof(buf));
	}

	Release(&engine);
	CoUninitialize();
	return 0;
}