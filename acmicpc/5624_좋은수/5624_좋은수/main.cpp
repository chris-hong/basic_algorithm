#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

/*
	���� d > a, b, c
	A(a) + A(b) + A(c) = A(d) �̸� �������̹Ƿ�..
	A(a) + A(b) = A(d) - A(c) �̸� ������
	
	-100,000 <= A(i) <= 100,000 �̹Ƿ�,
	-200,000 <= A(a) + A(b) <= 200,000 �� �ǰ�..
	200,000 ��ŭ SHIFT�Ͽ� 400,000���� ���۸� ����Ѵ�.
*/

int COUNT = 0;
int INPUT[5000];
bool IsGoodNum[400000];		// ���� ���� üũ�� ����

int main() {
	//freopen("input01.txt", "r", stdin);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> INPUT[i];
	}

	for (int target = 0; target < N; target++) {
		for (int idx = 0; idx < target; idx++) {
			int index = INPUT[target] - INPUT[idx] + 200000;
			if (IsGoodNum[index]) {
				// �ش� Range�� ���Ͽ� ���� ���� ����. Break.
				COUNT += 1;
				break;
			}
		}

		/* 
			���� target�� ���Ͽ� ���� �� �ĺ� ���. [A(a) + A(b)]�� ��� 
			[A(a) + A(b)]�� �ᱹ "������ ��ϵ� ���� ��" �� "A(0)~A(target) + A(target)"�� �� �����̴�. 
		*/
		for (int idx = 0; idx <= target; idx++) {
			int index = INPUT[idx] + INPUT[target] + 200000;
			IsGoodNum[index] = true;
		}
	}

	cout << COUNT << endl;
	return 0;
}