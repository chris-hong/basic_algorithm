#include <iostream>

int movingCount = 0;

void HanoiTowerAlg(int N, char from, char to, char mid) {
	if (N == 0) return;		// ���� ������ 0�̸� ��

	// ������ �� ����, �������� �������� �̵�
	HanoiTowerAlg(N - 1, from, mid, to);

	// ������ ���� �������� �̵�
	std::cout << "Move! " << N << "��° �� [" << from << "] -> [" << to << "]" << std::endl;
	movingCount++;

	// �������� �ִ� ���� �������� �̵�
	HanoiTowerAlg(N - 1, mid, to, from);
}

int main() {
	movingCount = 0;

	// A�� �ֿ��ִ� 5���� ž�� B�� �Űܶ�
	HanoiTowerAlg(5, 'A', 'B', 'C');
	std::cout << "�� ������ Ƚ��: " << movingCount << std::endl;

	getchar();
	return 0;
}