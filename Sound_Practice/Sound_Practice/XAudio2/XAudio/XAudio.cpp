#include "XAudio.h"
#include <cstdint>
#include <cassert>
#include <xaudio2.h>

#pragma comment(lib, "xaudio2.lib")

namespace {
	/*インスタンス数*/
	std::uint32_t instance = 0;
}

XAudio::XAudio() : 
	audio(nullptr), mastering(nullptr)
{
	Initialize();
}

XAudio::~XAudio()
{
	if (mastering != nullptr) {
		mastering->DestroyVoice();
		mastering = nullptr;
	}
	if (audio != nullptr) {
		audio->Release();
		audio = nullptr;
	}
}

void XAudio::CreateAudio(void)
{
	std::uint32_t flag = 0;
#ifdef _DEBUG
	flag = XAUDIO2_DEBUG_ENGINE;
#endif
	auto hr = XAudio2CreateWithVersionInfo(&audio, flag);
	assert(hr == S_OK);
}

void XAudio::CreateMastering(void)
{
	auto hr = audio->CreateMasteringVoice(&mastering);
	assert(hr == S_OK);
}

void XAudio::Initialize(void)
{
	CreateAudio();
	CreateMastering();
}

long CreateXAudio(XAudio** engine)
{
	if (instance == 0) {
		(*engine) = new XAudio();
		++instance;
		return S_OK;
	}
	
	return S_FALSE;
}

long Release(XAudio** engine)
{
	if ((*engine) != nullptr) {
		delete (*engine);
		--instance;
		return S_OK;
	}

	return S_FALSE;
}
