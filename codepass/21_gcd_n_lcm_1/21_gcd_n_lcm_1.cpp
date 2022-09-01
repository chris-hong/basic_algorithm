#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

bool check_input_N(int input)
{
	if (input < 1 || input > 10000)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

int get_GCD(int n1, int n2)
{
	if (n2 == 0) return n1;
	return get_GCD(n2, n1 % n2);
}

int main()
{
	cin >> N;
	cin >> M;

	if (check_input_N(N) && check_input_N(M))
	{
		int gcd = get_GCD(N, M);
		int lcm = N * M / gcd;

		cout << gcd << endl;
		cout << lcm << endl;
	}

	system("pause");

	return 0;
}