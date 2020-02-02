#pragma once

struct IXAudio2;
struct IXAudio2MasteringVoice;

class XAudio {
public:
	/*�R���X�g���N�^*/
	XAudio();
	/*�f�X�g���N�^*/
	~XAudio();

private:
	/*�I�[�f�B�I�̐���*/
	void CreateAudio(void);
	/*�}�X�^�����O�\�[�X�̐���*/
	void CreateMastering(void);
	/*�����o�̏�����*/
	void Initialize(void);

	/*�I�[�f�B�I*/
	IXAudio2* audio;
	/*�}�X�^�����O�{�C�X*/
	IXAudio2MasteringVoice* mastering;
};

/*XAudio�̐���
.XAudio*/
long CreateXAudio(XAudio** engine);
/*XAudio�̔j��
.XAudio*/
long Release(XAudio** engine);
