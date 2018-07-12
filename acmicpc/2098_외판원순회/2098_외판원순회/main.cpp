#include <iostream>
using namespace std;

const int INF = 987654321;
const int MAX = 16;
int N;
int W[MAX][MAX];
int CACHE[MAX][1 << MAX];	// �޸������̼ǿ� ����

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

// ���� �湮���� ���� ��� ��Ҹ� �湮�ϰ� �ٽ� ���������� ���ƿ��� �ּҰ��� ����
// �������� ���Ƿ� 0���� �����Ѵ�.(Shortest Path ������ �������� �����ϴ� ���� �����״�..)
// current: ���� ��ġ
// visited: ������ ��ġ���� bitmask��
int TSP(int current, int visited) {
	
	// ��������: ��� ������ �� �湮������, ���������� ���ư��� �Ѵ�.
	if (visited == (1 << N) - 1) {
		if (W[current][0]) {
			return W[current][0];
		}
		return INF;
	}

	// Ȥ��.. �̹� ���� ������ Ȯ���Ѵ�.(�޸������̼�)
	int& ret = CACHE[current][visited];
	if (ret != -1) return ret;	// -1�� �ƴϸ� �̹� ���� ���̴�.

	ret = INF;	// ���߿� MIN �� �ؾ��ϴ� ū������ �ʱ�ȭ

	// ���� ���� ���� ����� �� ��������. 
	for (int next = 0; next < N; next++) {
		if (visited & (1 << next)) continue;	// next�� �湮�� ���̸� SKIP
		if (!W[current][next]) continue;		// next�� ���� ���� ���̸� SKIP

		int cost = TSP(next, visited + (1 << next)) + W[current][next];
		ret = MIN(ret, cost);
	}

	return ret;
}

int main() {
	
	cin >> N;

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < 1 << MAX; j++) {
			CACHE[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> W[i][j];
		}
	}

	cout << TSP(0, 1) << endl;
	return 0;
}