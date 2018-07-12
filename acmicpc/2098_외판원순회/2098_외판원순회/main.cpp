#include <iostream>
using namespace std;

const int INF = 987654321;
const int MAX = 16;
int N;
int W[MAX][MAX];
int CACHE[MAX][1 << MAX];	// 메모이제이션용 버퍼

int MIN(int a, int b) {
	if (a > b) return b;
	return a;
}

// 아직 방문하지 않은 모든 장소를 방문하고 다시 시작점까지 돌아오는 최소값을 리턴
// 시작점을 임의로 0으로 설정한다.(Shortest Path 내에서 어디노드부터 시작하던 값은 같을테니..)
// current: 현재 위치
// visited: 지나온 위치들의 bitmask값
int TSP(int current, int visited) {
	
	// 종료조건: 모든 노드들을 다 방문했으면, 시작점으로 돌아가야 한다.
	if (visited == (1 << N) - 1) {
		if (W[current][0]) {
			return W[current][0];
		}
		return INF;
	}

	// 혹시.. 이미 계산된 값인지 확인한다.(메모이제이션)
	int& ret = CACHE[current][visited];
	if (ret != -1) return ret;	// -1이 아니면 이미 계산된 곳이다.

	ret = INF;	// 나중에 MIN 비교 해야하니 큰값으로 초기화

	// 아직 가지 않은 노드들로 더 진입하자. 
	for (int next = 0; next < N; next++) {
		if (visited & (1 << next)) continue;	// next가 방문한 곳이면 SKIP
		if (!W[current][next]) continue;		// next가 갈수 없는 곳이면 SKIP

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