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
	/*アルゴリズム*/
	std::int32_t(*algorithm)(Modulator*) = [](Modulator* mod)->std::int32_t {
		std::int32_t signal = mod->op[3].CreateSignalFB();
		signal = mod->op[2].CreateSignalModulation(signal);
		signal = mod->op[1].CreateSignalModulation(signal);
		signal = mod->op[0].CreateSignalModulation(signal);
		return signal;
	};
	/*パラメータ*/
	Parameter parameter = {
		{0.9f , 0.0f, 1.0f, 0.85f, 0.5f, 0.5f, 1.0f, 0.0f}, 
		{0.8f , 0.0f, 1.5f, 0.2f , 0.5f, 0.5f, 2.0f, 0.0f}, 
		{0.25f, 0.2f, 1.3f, 0.7f , 0.3f, 2.0f, 2.0f, 0.0f}, 
		{0.9f , 0.0f, 0.6f, 0.2f , 0.5f, 0.5f, 2.0f, 0.57f}
	};
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
	mod.ApplyAlgorithmFunc(algorithm);
	mod.ApplyParameter(parameter);
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