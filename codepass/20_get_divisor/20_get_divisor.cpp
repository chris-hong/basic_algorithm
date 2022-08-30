#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int K = 0;
set<int> divisor_set;
vector<int> divisor_list;

bool check_input_N(int input)
{
	if (input < 1 || input > 10000)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

bool check_intput_K(int input)
{
	if (input < 1 || input > N)
	{
		cout << "INPUT ERROR!" << endl;
		return false;
	}
	return true;
}

int main()
{
	cin >> N;
	cin >> K;

	if (check_input_N(N) && check_intput_K(K))
	{
		for (int i = 1; i <= sqrt(N); i++)
		{
			if (N % i == 0) {
				divisor_set.insert(i);
				divisor_set.insert(N / i);
			}
		}

		for (auto const& item : divisor_set) {
			divisor_list.push_back(item);
		}

		if (divisor_list.size() < K) cout << 0 << endl;
		else cout << divisor_list.at(K - 1) << endl;
	}

	system("pause");

	return 0;
}