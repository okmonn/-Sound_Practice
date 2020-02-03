#include "XAudio2/XAudio.h"
#include "FM����/Modulator.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

/*DxLib�̏�����*/
int DxInitialize(void) {
	//���O�̏o�͐���
	DxLib::SetOutApplicationLogValidFlag(false);
	//�O���t�B�b�N���[�h�̐ݒ�
	DxLib::SetGraphMode(640, 480, 32);
	//true:window�@false:�ٽ�ذ�
	DxLib::ChangeWindowMode(true);
	//window�e�L�X�g�̐ݒ�
	SetWindowText(_T("1601271_���ɒj"));
	//Dxlib�̏�����
	if (DxLib::DxLib_Init() == -1) {
		return -1;
	}
	//�}�E�X�J�[�\���̕\��
	DxLib::SetMouseDispFlag(true);
	//�ЂƂ܂��ޯ��ޯ̧�ɕ`��
	DxLib::SetDrawScreen(DX_SCREEN_BACK);

	return 0;
}
/*�`��*/
void DxDraw(void) {
	//��ʏ���
	DxLib::ClsDrawScreen();

	//����ʂ�\��ʂɏu�ԃR�s�[
	DxLib::ScreenFlip();
}
/*DxLib�̏I��*/
void DxEnd(void) {
	DxLib::DxLib_End();
}

int main() {
	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	XAudio* engine = nullptr;
	hr = CreateXAudio(&engine);
	SourceVoice voice(engine, 48000, 16, 1);
	std::int16_t buf[480];
	Modulator mod(48000);
	mod.SetFreq(440U);
	mod.Start();

	while (DxLib::ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		mod.CreateSignal(buf, _countof(buf));
		voice.Play(buf, _countof(buf));
	}

	hr = Release(&engine);
	CoUninitialize();

	return 0;
}