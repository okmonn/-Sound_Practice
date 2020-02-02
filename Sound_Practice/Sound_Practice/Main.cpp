#include "XAudio2/XAudio/XAudio.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

int main() {
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	XAudio* engine = nullptr;
	CreateXAudio(&engine);
	{
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
	}

	while (DxLib::ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//��ʏ���
		DxLib::ClsDrawScreen();

		for (std::int32_t i = -16; i < 11; ++i) {
			DxLib::DrawPixel(i + 16, (1 * std::pow(i, 2) + 6 * i + 20), GetColor(255, 0, 0));
		}

		//����ʂ�\��ʂɏu�ԃR�s�[
		DxLib::ScreenFlip();
	}

	DxLib::DxLib_End();

	Release(&engine);
	CoUninitialize();

	return 0;
}