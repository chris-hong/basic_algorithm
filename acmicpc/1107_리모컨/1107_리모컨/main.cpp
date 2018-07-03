#include <iostream>
using namespace std;

bool rcKeypad[10];

int DirectInput(int targetCH) {
	int count = 0;
	int ch = targetCH;

	// ��ǥ ä���� 0�̸�
	if (ch == 0) {
		if (rcKeypad[ch]) return 1;
		else return 0;
	}

	// ��ǥ ä���� 0�� �ƴϸ� (1 ~ 500,000)
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

	// ���峭 Ű�е��� ���� �Է�
	for (int i = 0; i < M; i++) {
		cin >> index;
		rcKeypad[index] = false;
	}

	// +, -�� ��ǥä�� ����
	pushCount = ABS(T - 100);

	// Ű�е带 �Է��Ͽ� �̵� �� ������ �κ� +, -�� ��ǥä�� ����
	for (int i = 0; i <= 1000000; i++) {
		int diCount = DirectInput(i);
		
		// Direct input�� ���� 0�̸� �ش� ���ڸ� ������ ���� ����̹Ƿ�.. ��ǥ ��ü�� ������ �ȵ�.
		if (diCount > 0) {
			pushCount = MIN(pushCount, diCount + ABS(T - i));
		}
	}

	cout << pushCount << endl;

	return 0;
}
