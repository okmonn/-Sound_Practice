#include "SourceVoice.h"
#include "../XAudio.h"
#include "../VoiceCallback.h"
#include <ks.h>
#include <cassert>
#include <ksmedia.h>

namespace {
	/*スピーカー一覧の定義*/
	const std::uint32_t spk[] = {
		KSAUDIO_SPEAKER_MONO,
		KSAUDIO_SPEAKER_STEREO,
	};
}

SourceVoice::SourceVoice(XAudio* engine, const std::uint32_t& sample, const std::uint8_t& bit, const std::uint8_t& channel, const bool& flag) :
	engine(engine), callback(std::make_unique<VoiceCallback>()), voice(nullptr), flag(false)
{
	CreateVoice(SetFormat(sample, bit, channel, flag));
	if (voice != nullptr) {
		this->engine->AddList(this);
	}
}

SourceVoice::~SourceVoice()
{
	if (voice != nullptr) {
		engine->DeleteList(this);
	}
	End();
}

void* SourceVoice::SetFormat(const std::uint32_t& sample, const std::uint8_t& bit, const std::uint8_t& channel, const bool& flag)
{
	static WAVEFORMATEXTENSIBLE fmt{};
	fmt.Format.cbSize          = sizeof(fmt) - sizeof(fmt.Format);
	fmt.Format.nSamplesPerSec  = sample;
	fmt.Format.wBitsPerSample  = bit;
	fmt.Format.nChannels       = channel;
	fmt.Format.nBlockAlign     = (fmt.Format.wBitsPerSample / 8) * fmt.Format.nChannels;
	fmt.Format.nAvgBytesPerSec = fmt.Format.nSamplesPerSec * fmt.Format.nBlockAlign;
	fmt.Format.wFormatTag      = WAVE_FORMAT_EXTENSIBLE;
	fmt.dwChannelMask               = spk[fmt.Format.nChannels - 1];
	fmt.Samples.wValidBitsPerSample = fmt.Format.wBitsPerSample;
	fmt.SubFormat                   = (flag == false) ? KSDATAFORMAT_SUBTYPE_PCM : KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;

	return (void*)&fmt;
}

void SourceVoice::CreateVoice(void* fmt)
{
	auto hr = engine->audio->CreateSourceVoice(&voice, (WAVEFORMATEX*)fmt, 0, 1.0f, &(*callback), nullptr, nullptr);
	assert(hr == S_OK);
}

void SourceVoice::Play(const std::int16_t* buf, const std::uint32_t& num)
{
	if (flag == false) {
		auto hr = voice->Start();
		assert(hr == S_OK);
		flag = true;
	}

	XAUDIO2_BUFFER desc{};
	desc.AudioBytes = std::uint32_t(sizeof(buf[0]) * num);
	desc.pAudioData = (std::uint8_t*)buf;

	auto hr = voice->SubmitSourceBuffer(&desc, nullptr);
	assert(hr == S_OK);

	WaitForSingleObjectEx(callback->handle, INFINITE, 0);
}

void SourceVoice::Stop(void)
{
	if (flag == true) {
		auto hr = voice->Stop();
		assert(hr == S_OK);
		flag = false;
	}
}

void SourceVoice::End(void)
{
	if (voice != nullptr) {
		voice->DestroyVoice();
		voice = nullptr;
	}
}
