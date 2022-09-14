#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

struct _CONVERT_SET {
	int A = 0;
	string N;
	int B = 0;
};

struct _CONVERT_SET CONVERT_SET[101];
int CNT = 0;

int ARRAY[65];
int IDX = 0;

bool check_input(int num)
{
	if (num < 2 || num > 36)
	{
		return false;
	}
	return true;
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

int translate_as_int(char ch)
{
	if (ch >= 65) return ch - 55;
	else return ch - 48;
}

long long power(int a, int n)
{
	long long res = 1;
	for (int i = 0; i < n; i++)
	{
		res *= a;
	}
	return res;
}

long long convert_from(int from, string str)
{
	int size = str.size();
	long long decimal = 0;
	for (int i = 0; i < size; i++)
	{
		long long n1 = power(from, size - i - 1);
		int n2 = translate_as_int(str.at(i));
		long long n3 = n1 * n2;
		decimal += n3;
	}
	return decimal;
}

void convert_to(long long num, int to)
{
	if (num / to == 0)
	{
		ARRAY[IDX] = num % to;
		IDX++;
		return;
	}
	else
	{
		convert_to(num / to, to);
	}
	ARRAY[IDX] = num % to;
	IDX++;
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
	while (true)
	{
		cin >> CONVERT_SET[CNT].A;
		if (!check_input(CONVERT_SET[CNT].A)) break;
		cin >> CONVERT_SET[CNT].N;
		cin >> CONVERT_SET[CNT].B;
		if (!check_input(CONVERT_SET[CNT].B)) break;
		CNT++;
	}
	
	for (int i = 0; i < CNT; i++)
	{
		memset(ARRAY, 0, sizeof(ARRAY));
		IDX = 0;

		long long decimal = convert_from(CONVERT_SET[i].A, CONVERT_SET[i].N);
		convert_to(decimal, CONVERT_SET[i].B);
		print();
	}

	system("pause");

	return 0;
}