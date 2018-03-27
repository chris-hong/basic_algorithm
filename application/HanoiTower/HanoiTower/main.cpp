#include <iostream>

int movingCount = 0;

void HanoiTowerAlg(int N, char from, char to, char mid) {
	if (N == 0) return;		// 판의 갯수가 0이면 끝

	// 마지막 판 빼고, 나머지를 경유지로 이동
	HanoiTowerAlg(N - 1, from, mid, to);

	// 마지막 판을 목적지로 이동
	std::cout << "Move! " << N << "번째 판 [" << from << "] -> [" << to << "]" << std::endl;
	movingCount++;

	// 경유지에 있는 판을 목적지로 이동
	HanoiTowerAlg(N - 1, mid, to, from);
}

int main() {
	movingCount = 0;

	// A에 쌍여있는 5개의 탑을 B로 옮겨라
	HanoiTowerAlg(5, 'A', 'B', 'C');
	std::cout << "총 움직임 횟수: " << movingCount << std::endl;

	getchar();
	return 0;
}