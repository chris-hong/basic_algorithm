#include <iostream>
using namespace std;

void Right_Rotate(int buf[], int start, int end) {
	int last = buf[end];
	for (int i = end; i >= start + 1; i--) {
		buf[i] = buf[i - 1];
	}
	buf[start] = last;
}

void Left_Rotate(int buf[], int start, int end) {
	int first = buf[start];
	for (int i = start; i <= end - 1; i++) {
		buf[i] = buf[i + 1];
	}
	buf[end] = first;
}

void Dictionary_Permutation(int buf[], int depth, int N) {
	if (depth == N) {
		for (int i = 0; i < N; i++) {
			cout << buf[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = depth; i < N; i++) {
		Right_Rotate(buf, depth, i);
		Dictionary_Permutation(buf, depth + 1, N);
		Left_Rotate(buf, depth, i);
	}
}

int main() {
	ios::sync_with_stdio(false);

	int N;
	int buf[8] = {};
	cin >> N;

	for (int i = 0; i < N; i++) {
		buf[i] = i + 1;
	}

	Dictionary_Permutation(buf, 0, N);

	return 0;
}

//#include <iostream>
//using namespace std;
//
//bool v[10];
//int tmp[10];
//
//void dfs(int num, int d, int n) {
//	tmp[d] = num;
//
//	if (d == n) {
//		for (int i = 1; i <= n; i++) {
//			cout << tmp[i] << " ";
//		}
//		cout << "\n";
//		return;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		if (v[i]) continue;
//		v[i] = true;
//		dfs(i, d + 1, n);
//		v[i] = false;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//
//	int n;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++) {
//		v[i] = true;
//		dfs(i, 1, n);
//		v[i] = false;
//	}
//
//	return 0;
//}