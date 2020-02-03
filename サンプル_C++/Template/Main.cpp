#include "Modulator/Modulator.h"
#include "Time/Time.h"
#include <Input.h>
#include <Voice.h>

#pragma comment(lib, "Input.lib")
#pragma comment(lib, "Sound.lib")

/*音階の周波数の取得*/
float GetNoteFreq(const unsigned char& note) {
	return 8.1758f * std::pow(std::pow(2.0f, 1.0f / 12.0f), float(note));
}

/*エントリーポイント*/
int main() {
	const unsigned int sample = 48000;

	Modulator mod(sample);
 	mod.InfluenceParameter(preset[0]);

	Voice voice({ sample, 16, 1 });
	std::vector<std::int16_t>buf(sample / 100);

	Time time;

	bool key = false;
	Input input;
	while (!input.CheckInput(KeyCode::Escape)) {
		if (input.CheckInput(KeyCode::Space)) {
			if (key == false) {
				key = true;
				mod.SetCreateFreq(GetNoteFreq(69));
				mod.Start();
			}
		}
		else {
			if (key == true) {
				key = false;
				mod.Stop();
			}
		}

		time.Begin();
		mod.CreateSignal(buf.data(), buf.size());
		time.End();
		voice.Play(buf.data(), buf.size());
	}

	return 0;
}