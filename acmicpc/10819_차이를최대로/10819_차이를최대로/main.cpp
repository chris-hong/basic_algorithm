#include <iostream>
using namespace std;

int ABS(int num1, int num2) {
	int v = num1 - num2;
	if (v >= 0) return v;
	else return -1 * v;
}

int MAX(int num1, int num2) {
	if (num1 > num2) return num1;
	else return num2;
}

/*
	본 문제는 선택된 값과 가장 차이가 큰값들을 계속해서 더하면 된다. 
	근데.. 시작값을 무엇으로 잡느냐에 따라 값이 달라질 수 있다.
	그런데.. 어떤값으로 시작을 해야 최대값이 나오는지 알수 없으므로..
	다해보는 수밖에 없다. Brute Force
	첫번째 For() 시작값을 입력값 모두 대입해보는 반복문
	
	아래의 2중 For()는 배열을 돌면서 선택한 값과 가장 차이가 큰 값을 찾으면서 순회하는 구문이다.
*/

int main() {
	int NUM[8];				// 입력받은 숫자 저장 배열 
	bool bSelection[8];		// 선택한 숫자 인덱스 체크용 배열
	
	int N;
	cin >> N;				// 입력값 저장
	for (int i = 0; i < N; i++) {
		cin >> NUM[i];
	}

	int finalSum = -1;		
	for (int i = 0; i < N; i++) {
		int caseSum = 0;			// 하나의 초기값이 선택되었을 때.. 그 값 기준으로 MaxDiffer들을 더한 값을 저장할 값.
		
		int selectValue = NUM[i];		// 초기값을 선택한 값으로 설정
		fill_n(bSelection, 8, false);	// 초기화 후에..
		bSelection[i] = true;			// 선택한 숫자 인덱스 체크

		for (int j = 0; j < N; j++) {
			int maxDiff = -1;			// 선택가능한 값들 중 가장 차이가 큰 값을 저장할 변수
			int maxDiffIdx = -1;		// 선택가능한 값들 중 가장 차이가 큰 값의 인덱스를 저장할 변수

			for (int k = 0; k < N; k++) {
				if (!bSelection[k]) {	// 선택한 값은 패스..
					int differ = ABS(selectValue, NUM[k]);	// 현재 선택한 값과의 차이 구하고..
					if (differ > maxDiff) {				// 가장 차이가 큰 값과 그값의 인덱스를 저장
						maxDiff = differ;
						maxDiffIdx = k;
					}
				}
			}
			if (maxDiff > -1) {					// 모두 다 체크된 경우 인덱스 오류나니까.. 예외처리 구문 넣고..
				bSelection[maxDiffIdx] = true;	// 가장 차이가 큰값이 선택되어야 하므로.. 그 인덱스 선택처리하고..
				selectValue = NUM[maxDiffIdx];		// 다음 선택값을 업데이트하고..
				caseSum += maxDiff;				// 차이 값을 계속 저장..
			}
		}
		finalSum = MAX(finalSum, caseSum);
	}

	cout << finalSum << endl;
	return 0;
}