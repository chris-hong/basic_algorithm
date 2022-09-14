#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main()
{
	string key;
	string statement;

	map<char, char> desc_map;

	getline(cin, key, '\n');
	getline(cin, statement, '\n');

	int key_size = key.size();
	for (int i = 0; i < key_size; i++)
	{
		char ch = key.at(i);
		desc_map.insert(pair<char, char>(char(97+i), ch));
	}

	int statement_size = statement.size();
	for (int i = 0; i < statement_size; i++)
	{
		char ch = statement.at(i);
		if (ch == ' ')
		{
			cout << " ";
		}
		else if (ch < 97)
		{
			char target = desc_map[ch + 32];
			cout << char(target - 32);
		}
		else
		{
			char target = desc_map[ch];
			cout << target;
		}
	}
	cout << endl;

	system("pause");

	return 0;
}