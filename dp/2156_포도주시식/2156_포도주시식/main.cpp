#include <iostream>

using namespace std;

/*
1�����迭 �̿� ���
A[N] : N��° ���� ������ ��
D[N] : 1 ~ N �ܱ��� ��Ģ�� ��Ű�� �����ָ� �Ծ����� ������ �ִ뷮
=> N�ܿ��� 3���� ��� �����ϰ� �׶��� ���� �Ʒ��� ����.
1) �ȸ��Ŵ� : D[N-1] 
2) ù�� : D[N-2] + A[N]
3) �ι�°�� : D[N-3] + A[N-1] + A[N]
=> �ִ뷮�̹Ƿ� MAX(1,2,3)
*/

int Max(int a, int b, int c) {
	int max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	return max;
}

int main() {
	int A[10001] = {};
	int D[10001] = {};
	
	int N;
	cin >> N; cin.get();
	
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; cin.get();
	}

	D[1] = A[1];
	D[2] = A[1] + A[2];

	for (int i = 3; i <= N; i++) {
		D[i] = Max(D[i - 1],
				D[i - 2] + A[i],
				D[i - 3] + A[i - 1] + A[i]);
	}

	cout << "=> " << D[N] << endl;

	getchar();
	return 0;
}