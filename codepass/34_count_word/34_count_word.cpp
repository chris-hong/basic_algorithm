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

list<pair<string, int>> chunk_list;

bool compare_item(const pair<string, int>& item1, const pair<string, int>& item2)
{
	return item1.first < item2.first;
}

void insert_to_word_set(string chunk)
{
	bool is_exist = false;
	for (auto it = chunk_list.begin(); it != chunk_list.end(); it++)
	{
		if (it->first == chunk)
		{
			is_exist = true;
			it->second += 1;
			break;
		}
	}
	if (!is_exist)
	{
		chunk_list.push_back(pair<string, int>(chunk, 1));
	}
}

void print_chunk_list()
{
	chunk_list.sort(compare_item);

	for (auto const& item : chunk_list)
	{
		printf("%s : %d\n", item.first.c_str(), item.second);
	}
}

void process_input(string input)
{
	size_t prev_idx = 0;
	size_t next_idx = 0;
	size_t input_length = input.size();

	while (next_idx != input_length)
	{
		next_idx = input.find(' ', prev_idx);
		if (next_idx > 200) next_idx = input_length;
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
		chunk_list.clear();
	}

	system("pause");

	return 0;
}