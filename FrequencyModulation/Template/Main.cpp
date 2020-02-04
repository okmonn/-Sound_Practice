#include "FrequencyModulation/Modulator.h"

namespace {
	/*サンプリング周波数*/
	const std::uint32_t sample = 48000;
	/*アルゴリズムのプリセット*/
	std::int32_t(*algorithm[])(Modulator*) = {
		[](Modulator* mod)->std::int32_t {
			std::int32_t signal = mod->op[3].CreateSignalFB();
			signal = mod->op[2].CreateSignalModulation(signal);
			signal = mod->op[1].CreateSignalModulation(signal);
			signal = mod->op[0].CreateSignalModulation(signal);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t pcm = mod->op[3].CreateSignalFB();
			std::int32_t signal = mod->op[2].CreateSignalSimple();
			signal = mod->op[1].CreateSignalModulation(signal + pcm);
			signal = mod->op[0].CreateSignalModulation(signal);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t pcm = mod->op[3].CreateSignalFB();
			std::int32_t signal = mod->op[2].CreateSignalSimple();
			signal = mod->op[1].CreateSignalModulation(signal);
			signal = mod->op[0].CreateSignalModulation(signal + pcm);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t signal = mod->op[3].CreateSignalFB();
			signal = mod->op[2].CreateSignalModulation(signal);
			std::int32_t pcm = mod->op[1].CreateSignalSimple();
			signal = mod->op[0].CreateSignalModulation(signal + pcm);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t signal = mod->op[3].CreateSignalFB();
			signal = mod->op[2].CreateSignalModulation(signal);
			std::int32_t pcm = mod->op[1].CreateSignalSimple();
			signal += mod->op[0].CreateSignalModulation(pcm);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t pcm = mod->op[3].CreateSignalFB();
			std::int32_t signal = mod->op[2].CreateSignalModulation(pcm);
			signal += mod->op[1].CreateSignalModulation(pcm);
			signal += mod->op[0].CreateSignalModulation(pcm);
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t signal = mod->op[3].CreateSignalFB();
			signal = mod->op[2].CreateSignalModulation(signal);
			signal += mod->op[1].CreateSignalSimple();
			signal += mod->op[0].CreateSignalSimple();
			return signal;
		},
		[](Modulator* mod)->std::int32_t {
			std::int32_t signal = mod->op[3].CreateSignalFB();
			signal += mod->op[2].CreateSignalSimple();
			signal += mod->op[1].CreateSignalSimple();
			signal += mod->op[0].CreateSignalSimple();
			return signal;
		},
	};
	/*パラメータのプリセット*/
	const Parameter parameter[] = {
		 /*SYN_BASS(2)*/
		{{0.9f , 0.0f, 1.0f, 0.85f, 0.5f, 0.5f, 1.0f, 0.0f},
		 {0.8f , 0.0f, 1.5f, 0.2f , 0.5f, 0.5f, 2.0f, 0.0f}, 
		 {0.25f, 0.2f, 1.3f, 0.7f , 0.3f, 2.0f, 2.0f, 0.0f},
		 {0.9f , 0.0f, 0.6f, 0.2f , 0.5f, 0.5f, 2.0f, 0.57f}},
		 /*BELL(4)*/
		{{0.9f , 0.0f, 6.0f, 0.15f, 0.5f, 1.0f, 0.5f, 0.0f},
		 {0.5f , 0.0f, 6.0f, 0.1f , 0.5f, 3.5f, 1.0f, 0.0f},
		 {0.85f, 0.0f, 6.3f, 0.4f , 0.5f, 1.0f, 0.5f, 0.0f},
		 {0.7f , 0.0f, 6.0f, 0.1f , 0.5f, 3.5f, 1.0f, 0.01f}},
		 /*DX_PIANO(4)*/
		{{0.9f , 0.0f , 6.0f, 2.0f , 0.5f, 1.0f, 0.5f, 0.0f},
		 {0.8f , 0.0f , 0.3f, 0.01f, 0.5f, 1.0f, 1.0f, 0.0f},
		 {0.85f, 0.15f, 3.5f, 0.3f , 1.0f, 1.0f, 0.5f, 0.0f},
		 {0.5f , 0.0f , 1.0f, 0.3f , 0.8f, 2.0f, 1.0f, 0.15f}},
		 /*SYN_BRASS(0)*/
		{{0.9f , 0.1f, 0.2f, 0.7f , 1.0f, 1.0f, 2.0f, 0.0f},
		 {0.25f, 0.0f, 0.5f, 0.7f , 0.5f, 1.0f, 2.0f, 0.0f},
		 {0.75f, 0.1f, 0.5f, 0.5f , 0.5f, 0.5f, 2.0f, 0.0f},
		 {0.4f , 0.0f, 0.4f, 0.05f, 0.5f, 3.0f, 1.0f, 0.28f}},
		 /*PIPE_ORGAN(7)*/
		{{1.0f, 0.05f, 0.25f, 1.0f, 0.5f, 0.5f, 0.25f, 0.0f},
		 {1.0f, 0.0f , 0.25f, 1.0f, 0.8f, 2.0f, 0.25f, 0.0f},
		 {0.9f, 0.1f , 0.15f, 1.0f, 1.2f, 1.0f, 0.25f, 0.0f},
		 {0.3f, 0.4f , 0.1f , 0.4f, 1.2f, 4.0f, 0.25f, 1.0f}},
	};
}

/*エントリーポイント*/
int main() {
	Modulator mod;
	mod.SetSample(sample);
	mod.ApplyParameter(parameter[0]);
	mod.ApplyAlgorithmFunc(algorithm[2]);
	mod.SetFreq(440U);
	mod.Start();

	std::int16_t buf[sample / 100];
	mod.CreateSignal(buf, sample / 100);

	mod.Stop();
	return 0;
}