#include <iostream>
//#pragma warning(disable:4996)
using namespace std;

/*
	조건 d > a, b, c
	A(a) + A(b) + A(c) = A(d) 이면 좋은수이므로..
	A(a) + A(b) = A(d) - A(c) 이면 좋은수
	
	-100,000 <= A(i) <= 100,000 이므로,
	-200,000 <= A(a) + A(b) <= 200,000 이 되고..
	200,000 만큼 SHIFT하여 400,000개의 버퍼를 사용한다.
*/

int COUNT = 0;
int INPUT[5000];
bool IsGoodNum[400000];		// 좋은 수를 체크할 버퍼

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
				// 해당 Range에 대하여 좋은 수가 있음. Break.
				COUNT += 1;
				break;
			}
		}

		/* 
			다음 target을 위하여 좋은 수 후보 등록. [A(a) + A(b)]를 등록 
			[A(a) + A(b)]는 결국 "기존의 등록된 좋은 수" 와 "A(0)~A(target) + A(target)"의 합 집합이다. 
		*/
		for (int idx = 0; idx <= target; idx++) {
			int index = INPUT[idx] + INPUT[target] + 200000;
			IsGoodNum[index] = true;
		}
	}

	cout << COUNT << endl;
	return 0;
}