#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <set>
#include <vector>
#include <map>
#include <list>

using namespace std;

list<string> chunk_list;

void insert_to_word_set(string chunk)
{
	bool is_exist = false;
	for (string& str : chunk_list)
	{
		if (str == chunk)
		{
			is_exist = true;
			break;
		}
	}

	if (!is_exist) chunk_list.push_back(chunk);
}

void print_chunk_list()
{
	for (string& chunk : chunk_list)
	{
		cout << chunk << " ";
	}
	cout << endl;
}

void process_input(string input)
{
	size_t prev_idx = 0;
	size_t next_idx = 0;
	size_t input_length = input.size();

	while (next_idx != input_length)
	{
		next_idx = input.find(' ', prev_idx);
		if (next_idx > 100) next_idx = input_length;
		string chunk = input.substr(prev_idx, next_idx - prev_idx);
		prev_idx = next_idx + 1;

		if (chunk != " ") insert_to_word_set(chunk);
	}
	print_chunk_list();
}

int main()
{
	string input;

	while (true)
	{
		getline(cin, input, '\n');
		if (input == "END") break;
		process_input(input);
	}

	system("pause");

	return 0;
}