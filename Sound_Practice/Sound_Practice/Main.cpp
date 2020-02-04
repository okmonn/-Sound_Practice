#include "XAudio2/XAudio.h"
#include "FM����/Modulator.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

namespace {
	/*�T���v�����O���g��*/
	const std::uint32_t sample = 48000;
	/*�ʎq���r�b�g��*/
	const std::uint8_t bit = 16;
	/*�`�����l����*/
	const std::uint8_t channel = 1;

	Parameter pr = {
		{{ 0.9f , 0.0f, 1.0f, 0.85f, 0.5f, 0.5f, 1.0f, 0.0f }, 
		 { 0.8f , 0.0f, 1.5f, 0.2f , 0.5f, 0.5f, 2.0f, 0.0f }, 
		 { 0.25f, 0.2f, 1.3f, 0.7f , 0.3f, 0.5f, 2.0f, 0.0f },
		 { 0.9f , 0.0f, 0.6f, 0.2f , 0.5f, 0.5f, 2.0f, 0.57f}}
	};
}

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
	for (int i = -10; i < 0; ++i) {
		DxLib::DrawPixel(i + 10, std::pow(i, 2) - i, GetColor(255, 0, 0));
	}
	//����ʂ�\��ʂɏu�ԃR�s�[
	DxLib::ScreenFlip();
}
/*DxLib�̏I��*/
void DxEnd(void) {
	DxLib::DxLib_End();
}

int main() {
	DxInitialize();

	auto hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	XAudio* engine = nullptr;
	hr = CreateXAudio(&engine);
	SourceVoice voice(engine, sample, bit, channel);
	std::int16_t buf[480];
	Modulator mod(sample);
	mod.ApplyParameter(pr);
	
	bool key = false;
	while (DxLib::ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if (DxLib::CheckHitKey(KEY_INPUT_SPACE) != 0) {
			if (key == false) {
				key = true;
				mod.SetFreq(440U);
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
		//DxDraw();
	}
	DxEnd();
	hr = Release(&engine);
	CoUninitialize();
	return 0;
}