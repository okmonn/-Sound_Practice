#pragma once
#include <cstdint>
#include <xaudio2.h>

struct VoiceCallback : 
	public IXAudio2VoiceCallback {
public:
	/*コンストラクタ*/
	VoiceCallback() {
		handle = CreateEventEx(nullptr, nullptr, 0, EVENT_ALL_ACCESS);
	}
	/*デストラクタ*/
	~VoiceCallback() {
		if (handle != nullptr) {
			CloseHandle(handle);
			handle = nullptr;
		}
	}
	void __stdcall OnVoiceProcessingPassStart(UINT SamplesRequired) {}
	void __stdcall OnVoiceProcessingPassEnd() {}
	void __stdcall OnBufferStart(void* pBufferContext) {}
	void __stdcall OnBufferEnd(void* pBufferContext) { 
		SetEvent(handle);
	}
	void __stdcall OnStreamEnd() {}
	void __stdcall OnLoopEnd(void* pBufferContext) {}
	void __stdcall OnVoiceError(void* pBufferContext, HRESULT Error) {}

public:
	/*イベントハンドル*/
	void* handle;
};
