#pragma once

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio {
public:
	/*コンストラクタ*/
	XAudio();
	/*デストラクタ*/
	~XAudio();

private:
	/*オーディオの生成*/
	void CreateAudio(void);
	/*マスタリングソースの生成*/
	void CreateMastering(void);
	/*メンバの初期化*/
	void Initialize(void);

	/*オーディオ*/
	IXAudio2* audio;
	/*マスタリングボイス*/
	IXAudio2MasteringVoice* mastering;
};

/*XAudioの生成
.XAudio*/
long CreateXAudio(XAudio** engine);
/*XAudioの破棄
.XAudio*/
long Release(XAudio** engine);
