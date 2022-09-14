#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int N = 0;
int B = 0;
int IDX = 0;
int ARRAY[20];

bool check_input_N()
{
	if (N < 1 || N > 100000)
	{
		cout << "Input Error!" << endl;
		return false;
	}
	return true;
}

bool check_input_B()
{
	if (B == 2 || B == 8 || B == 16)
	{
		return true;
	}
	else
	{
		cout << "Input Error!" << endl;
		return false;
	}
}

void convert_B(int num)
{
	if (num / B == 0)
	{
		ARRAY[IDX] = num % B;
		IDX++;
		return;
	}
	else
	{
		convert_B(num / B);
	}
	ARRAY[IDX] = num % B;
	IDX++;
}

char translate_as_ascii(int num)
{
	if (num >= 10)
	{
		return num + 55;
	}
	else
	{
		return num + 48;
	}
}

void print()
{
	for (int i = 0; i < IDX; i++)
	{
		cout << translate_as_ascii(ARRAY[i]);
	}
	cout << endl;
}

int main()
{
	cin >> N;
	cin >> B;

	if (check_input_N() && check_input_B())
	{
		convert_B(N);
		print();
	}

	system("pause");

	return 0;
}