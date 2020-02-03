#pragma once

/*オペレータの最大数*/
#define OP_MAX 4

/*動作状態*/
enum class STATE {
	/*停止*/
	stop,
	/*実行*/
	execute
};

/*エンベロープの動作状態*/
enum class EV_STATE {
	/*開始*/
	start,
	/*アタック*/
	attack,
	/*ディケイ*/
	decay,
	/*サスティン*/
	sustain,
	/*ノートオフ*/
	note_off,
	/*リリース*/
	release,
};

/*オペレータの周波数タイプ*/
enum class TYPE {
	/*比率表現*/
	variable,
	/*固定表現*/
	fix
};
