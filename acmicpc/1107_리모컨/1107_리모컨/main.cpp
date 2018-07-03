#include <iostream>
using namespace std;

bool rcKeypad[10];

int DirectInput(int targetCH) {
	int count = 0;
	int ch = targetCH;

	// 목표 채널이 0이면
	if (ch == 0) {
		if (rcKeypad[ch]) return 1;
		else return 0;
	}

	// 목표 채널이 0이 아니면 (1 ~ 500,000)
	while (ch > 0) {
		if (rcKeypad[ch % 10]) count += 1;
		else return 0;

		ch = ch / 10;
	}

	return count;
}

int ABS(int num) {
	if (num >= 0) return num;
	else return num * -1;
}

int MIN(int num1, int num2) {
	if (num1 > num2) return num2;
	else return num1;
}

int main() {
	int T, M;
	int index;

	fill_n(rcKeypad, 10, true);

	cin >> T;
	cin >> M;

	int pushCount = 0;

	// 고장난 키패드의 숫자 입력
	for (int i = 0; i < M; i++) {
		cin >> index;
		rcKeypad[index] = false;
	}

	// +, -로 목표채널 도달
	pushCount = ABS(T - 100);

	// 키패드를 입력하여 이동 후 부족한 부분 +, -로 목표채널 도달
	for (int i = 0; i <= 1000000; i++) {
		int diCount = DirectInput(i);
		
		// Direct input의 값이 0이면 해당 숫자를 누를수 없는 경우이므로.. 목표 자체가 성립이 안됨.
		if (diCount > 0) {
			pushCount = MIN(pushCount, diCount + ABS(T - i));
		}
	}

	cout << pushCount << endl;

	return 0;
}
