#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

char N[32];

int check_length()
{
	int cnt = 0;
	char* ch = N;

	while (ch[cnt] != 0)
	{
		cnt++;
	}
	return cnt;
}

int main()
{
	int decimal = 0;
	memset(N, 0, sizeof(N));

	cin >> N;

	int length_N = check_length();

	for (int i = 0; i < length_N; i++)
	{
		decimal = decimal << 1;
		char digit = N[i];
		decimal += atoi(&digit);
	}

	cout << decimal << endl;

	system("pause");

	return 0;
}