#include <iostream>
#include <random>
#include "BST.h"
using namespace std;

int main() {
	const int MAX = 10;
	const int MAX_RANGE = 1000;

	int* buffer = new int[MAX];

	BST bst;

	random_device rd;
	mt19937_64 rand(rd());
	uniform_int_distribution<int> range(0, MAX_RANGE - 1);

	int count = 0;
	while (count < MAX) {
		int num = range(rand);
		if (!bst.IsExist(num)) {
			bst.Insert(num);
			buffer[count] = num;
			count += 1;
		}
	}

	bst.Print();

	for (int i = count - 1; i >= 0; i--) {
		cout << i << " Remove: " << buffer[i] << endl;
		bst.Remove(buffer[i]);
	}

	return 0;
}