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

/* 에라토스테네스의 체 */
/* 0, 1은 일단 제외하고, 소수인 2부터 순차적으로 2의 배수들을 합성수 표기한다. */
/* 순차적으로 증가하며 살펴볼 때, 합성수 표기가 안된 숫자들은 소수이지만, 소수의 배수는 합성수이므로 표기한다. */
/* 여기서 하나 더, 소수를 발견하고 때, 소수의 배수를 표기시에.. N-1의 배수는 이미 이전에 표기했으므로, */
/* 바로 N*N으로 넘어가서 그때부터 그 이상의 N배수들을 표기하면 된다. */
/* 마지막으로 순차적으로 증가하는 범위는 N*N <= MAX까지만 순차증가를 하면 되는데, */ 
/* 이는 앞과 마찬가지로 MAX보다 작은 N-1의 배수들은 이미 마킹이 완료된 상태이기 때문이다. */
void make_eratosthenes()
{
	ARRAY[0] = ARRAY[1] = 1;	// 0, 1 은 소수에서 제외므로 일단 제외(1 처리)
	for (int i = 2; i*i <= MAX; i++)
	{
		/* 2는 소수, 2의 배수는 합성수 */
		/* 3은 소수, 3의 배수는 합성수 */
		/* N이 소수라면, N의 배수는 합성수 */
		if (ARRAY[i] == 0)
		{
			/* N의 제곱부터 검사를 하면 되는 이유는 앞서 N-1의 배수는 모두 합성수 표기했기 때문이다. */
			/* N의 제곱부터 N의 배수들을 차례대로 합성수 표기한다. */
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

		/* N부터 M까지 소수의 갯수는 에라토스테네스의 체에서 0의 갯수를 카운팅하면 된다. */
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