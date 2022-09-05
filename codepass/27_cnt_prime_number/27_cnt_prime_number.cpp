#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

const int MAX = 2000001;
static int ARRAY[MAX];

bool check_input(int input)
{
	if (input < 0 || input > 2 * pow(10, 6))
	{
		return false;
	}
	return true;
}

//bool is_prime_number(int num)
//{
//	if (num < 2) return false;
//	int sqrt_num = (int)sqrt(num);
//	for (int i = 2; i <= sqrt_num; i++)
//	{
//		if (num % i == 0) return false;
//	}
//	return true;
//}

//int main()
//{
//	cin >> N;
//	cin >> M;
//
//	int PRIME_SUM = 0;
//	if (check_input(N) && check_input(M))
//	{
//		for (int i = N; i < M; i++)
//		{
//			if (is_prime_number(i)) PRIME_SUM++;
//		}
//		cout << PRIME_SUM << endl;
//	}
//
//	system("pause");
//
//	return 0;
//}

/* �����佺�׳׽��� ü */
/* 0, 1�� �ϴ� �����ϰ�, �Ҽ��� 2���� ���������� 2�� ������� �ռ��� ǥ���Ѵ�. */
/* ���������� �����ϸ� ���캼 ��, �ռ��� ǥ�Ⱑ �ȵ� ���ڵ��� �Ҽ�������, �Ҽ��� ����� �ռ����̹Ƿ� ǥ���Ѵ�. */
/* ���⼭ �ϳ� ��, �Ҽ��� �߰��ϰ� ��, �Ҽ��� ����� ǥ��ÿ�.. N-1�� ����� �̹� ������ ǥ�������Ƿ�, */
/* �ٷ� N*N���� �Ѿ�� �׶����� �� �̻��� N������� ǥ���ϸ� �ȴ�. */
/* ���������� ���������� �����ϴ� ������ N*N <= MAX������ ���������� �ϸ� �Ǵµ�, */ 
/* �̴� �հ� ���������� MAX���� ���� N-1�� ������� �̹� ��ŷ�� �Ϸ�� �����̱� �����̴�. */
void make_eratosthenes()
{
	ARRAY[0] = ARRAY[1] = 1;	// 0, 1 �� �Ҽ����� ���ܹǷ� �ϴ� ����(1 ó��)
	for (int i = 2; i*i <= MAX; i++)
	{
		/* 2�� �Ҽ�, 2�� ����� �ռ��� */
		/* 3�� �Ҽ�, 3�� ����� �ռ��� */
		/* N�� �Ҽ����, N�� ����� �ռ��� */
		if (ARRAY[i] == 0)
		{
			/* N�� �������� �˻縦 �ϸ� �Ǵ� ������ �ռ� N-1�� ����� ��� �ռ��� ǥ���߱� �����̴�. */
			/* N�� �������� N�� ������� ���ʴ�� �ռ��� ǥ���Ѵ�. */
			for (int j = i * i; j <= MAX; j += i)
			{
				ARRAY[j] = 1;
			}
		}
	}
}


int main()
{
	cin >> N;
	cin >> M;

	int PRIME_SUM = 0;
	if (check_input(N) && check_input(M))
	{
		make_eratosthenes();

		/* N���� M���� �Ҽ��� ������ �����佺�׳׽��� ü���� 0�� ������ ī�����ϸ� �ȴ�. */
		for (int i = N; i <= M; i++)
		{
			if (ARRAY[i] == 0) 
				PRIME_SUM++;
		}
		cout << PRIME_SUM << endl;
	}

	system("pause");

	return 0;
}