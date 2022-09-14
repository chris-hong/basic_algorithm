#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

int main()
{
	string input;

	cin >> input;

	int size = input.size();
	int p = 0;
	int koi = 0;
	int ioi = 0;

	if (size > 0)
	{
		while (p < size - 2)
		{
			char ch = input.at(p);

			if (ch == 'K')
			{
				char ch2 = input.at(p + 1);
				char ch3 = input.at(p + 2);
				if (ch2 == 'O' && ch3 == 'I')
				{
					koi++;
					p += 2;
					continue;
				}
			}
			else if (ch == 'I')
			{
				char ch2 = input.at(p + 1);
				char ch3 = input.at(p + 2);
				if (ch2 == 'O' && ch3 == 'I')
				{
					ioi++;
					p += 2;
					continue;
				}
			}
			p++;
		}
	}
	
	cout << koi << endl;
	cout << ioi << endl;

	system("pause");

	return 0;
}