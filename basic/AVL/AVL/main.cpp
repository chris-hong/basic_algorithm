#include <random>
#include "AVL.h"

int main() {
	const int MAX = 100;
	const int MAX_RANGE = 1000;

	int* buffer = new int[MAX];

	std::random_device rd;
	std::mt19937_64 rand(rd());
	std::uniform_int_distribution<int> range(0, MAX_RANGE - 1);

	AVL<int> avl;
	int count = 0;

	while (count < MAX) {
		int num = range(rand);
		if (!avl.IsExist(num)) {
			avl.Insert(num);
			buffer[count] = num;
			count += 1;
		}
	}

	avl.Print();

	for (int i = 0; i < count; i++) {
		cout << i << " Remove: " << buffer[i] << endl;
		avl.Remove(buffer[i]);
	}

	delete buffer;

	return 0;
}