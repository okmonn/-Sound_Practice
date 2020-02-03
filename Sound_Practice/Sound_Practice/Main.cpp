#include "XAudio2/XAudio.h"
#include "FM音源/Modulator.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

/*DxLibの初期化*/
int DxInitialize(void) {
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

	return 0;
}
/*描画*/
void DxDraw(void) {
	//画面消去
	DxLib::ClsDrawScreen();

	//裏画面を表画面に瞬間コピー
	DxLib::ScreenFlip();
}
/*DxLibの終了*/
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