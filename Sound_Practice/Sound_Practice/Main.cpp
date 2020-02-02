#include "XAudio2/XAudio/XAudio.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

int main() {
	CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	XAudio* engine = nullptr;
	CreateXAudio(&engine);
	{
		//ログの出力制御
		DxLib::SetOutApplicationLogValidFlag(false);
		//グラフィックモードの設定
		DxLib::SetGraphMode(640, 480, 32);
		//true:window　false:ﾌﾙｽｸﾘｰﾝ
		DxLib::ChangeWindowMode(true);
		//windowテキストの設定
		SetWindowText(_T("1601271_岡繁男"));
		//Dxlibの初期化
		if (DxLib::DxLib_Init() == -1) {
			return -1;
		}
		//マウスカーソルの表示
		DxLib::SetMouseDispFlag(true);
		//ひとまずﾊﾞｯｸﾊﾞｯﾌｧに描画
		DxLib::SetDrawScreen(DX_SCREEN_BACK);
	}

	while (DxLib::ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//画面消去
		DxLib::ClsDrawScreen();

		for (std::int32_t i = -16; i < 11; ++i) {
			DxLib::DrawPixel(i + 16, (1 * std::pow(i, 2) + 6 * i + 20), GetColor(255, 0, 0));
		}

		//裏画面を表画面に瞬間コピー
		DxLib::ScreenFlip();
	}

	DxLib::DxLib_End();

	Release(&engine);
	CoUninitialize();

	return 0;
}