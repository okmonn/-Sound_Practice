#pragma once
#include <cstdint>

class Time {
public:
	/*コンストラクタ*/
	Time();
	/*デストラクタ*/
	~Time();
	/*計測の開始*/
	void Begin(void);
	/*計測の終了
	return 計測結果(ナノ秒)*/
	std::uint64_t End(void);
	/*計測結果の取得
	return 計測結果*/
	std::uint64_t GetResult(void) const;

private:
	/*開始時刻*/
	std::uint64_t begin;
	/*終了時刻*/
	std::uint64_t end;
	/*計測結果*/
	std::uint64_t result;
};
