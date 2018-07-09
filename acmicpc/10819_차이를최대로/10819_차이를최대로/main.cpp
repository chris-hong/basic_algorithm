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
	�� ������ ���õ� ���� ���� ���̰� ū������ ����ؼ� ���ϸ� �ȴ�. 
	�ٵ�.. ���۰��� �������� ����Ŀ� ���� ���� �޶��� �� �ִ�.
	�׷���.. ������� ������ �ؾ� �ִ밪�� �������� �˼� �����Ƿ�..
	���غ��� ���ۿ� ����. Brute Force
	ù��° For() ���۰��� �Է°� ��� �����غ��� �ݺ���
	
	�Ʒ��� 2�� For()�� �迭�� ���鼭 ������ ���� ���� ���̰� ū ���� ã���鼭 ��ȸ�ϴ� �����̴�.
*/

int main() {
	int NUM[8];				// �Է¹��� ���� ���� �迭 
	bool bSelection[8];		// ������ ���� �ε��� üũ�� �迭
	
	int N;
	cin >> N;				// �Է°� ����
	for (int i = 0; i < N; i++) {
		cin >> NUM[i];
	}

	int finalSum = -1;		
	for (int i = 0; i < N; i++) {
		int caseSum = 0;			// �ϳ��� �ʱⰪ�� ���õǾ��� ��.. �� �� �������� MaxDiffer���� ���� ���� ������ ��.
		
		int selectValue = NUM[i];		// �ʱⰪ�� ������ ������ ����
		fill_n(bSelection, 8, false);	// �ʱ�ȭ �Ŀ�..
		bSelection[i] = true;			// ������ ���� �ε��� üũ

		for (int j = 0; j < N; j++) {
			int maxDiff = -1;			// ���ð����� ���� �� ���� ���̰� ū ���� ������ ����
			int maxDiffIdx = -1;		// ���ð����� ���� �� ���� ���̰� ū ���� �ε����� ������ ����

			for (int k = 0; k < N; k++) {
				if (!bSelection[k]) {	// ������ ���� �н�..
					int differ = ABS(selectValue, NUM[k]);	// ���� ������ ������ ���� ���ϰ�..
					if (differ > maxDiff) {				// ���� ���̰� ū ���� �װ��� �ε����� ����
						maxDiff = differ;
						maxDiffIdx = k;
					}
				}
			}
			if (maxDiff > -1) {					// ��� �� üũ�� ��� �ε��� �������ϱ�.. ����ó�� ���� �ְ�..
				bSelection[maxDiffIdx] = true;	// ���� ���̰� ū���� ���õǾ�� �ϹǷ�.. �� �ε��� ����ó���ϰ�..
				selectValue = NUM[maxDiffIdx];		// ���� ���ð��� ������Ʈ�ϰ�..
				caseSum += maxDiff;				// ���� ���� ��� ����..
			}
		}
		finalSum = MAX(finalSum, caseSum);
	}

	cout << finalSum << endl;
	return 0;
}