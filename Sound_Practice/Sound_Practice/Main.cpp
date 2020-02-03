#include "XAudio2/XAudio.h"
#include "FM音源/Modulator.h"

#include <DxLib.h>
#include <cmath>
#include <cstdint>

namespace {
	/*サンプリング周波数*/
	const std::uint32_t sample = 48000;
	/*量子化ビット数*/
	const std::uint8_t bit = 16;
	/*チャンネル数*/
	const std::uint8_t channel = 1;
}

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
	for (int i = -10; i < 0; ++i) {
		DxLib::DrawPixel(i + 10, std::pow(i, 2) - i, GetColor(255, 0, 0));
	}
	//裏画面を表画面に瞬間コピー
	DxLib::ScreenFlip();
}
/*DxLibの終了*/
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
	mod.SetFreq(440U);
	mod.Start();

	while (DxLib::ProcessMessage() == 0 && DxLib::CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		mod.CreateSignal(buf, _countof(buf));
		voice.Play(buf, _countof(buf));
		//DxDraw();
	}
	DxEnd();
	hr = Release(&engine);
	CoUninitialize();
	return 0;
}