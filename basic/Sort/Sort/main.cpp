#include <iostream>
#include <random>
#include <string>

#include "bubbleSort.h"
#include "selectSort.h"
#include "insertSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heap.h"

int N = 100;
int MIXCOUNT = 1000;
int* Buffer;

void Initialize_Buffer(int _N) {
	Buffer = new int[_N];
	for (int i = 0; i < _N; i++) {
		Buffer[i] = i + 1;
	}
}

void Uninitialize_Buffer() {
	delete Buffer;
}

void Mix_Buffer(int mixCount, int _range) {
	std::random_device rn;
	std::mt19937_64 rnd(rn());
	std::uniform_int_distribution<int> range(0, _range - 1);

	for (int i = 0; i < mixCount; i++) {
		int pIdx = range(rnd);
		int nIdx = range(rnd);
		int temp = Buffer[pIdx];
		Buffer[pIdx] = Buffer[nIdx];
		Buffer[nIdx] = temp;
	}
	
}

void Show_Buffer(int _N, std::string desc, std::string sortName = "") {
	std::cout << "=== [ " << desc << " ] ===" << std::endl;
	int i = 0;
	
	if (sortName != "") {
		std::cout << "[" << sortName << "] ";
	}

	for (i = 0; i < _N; i++) {
		std::cout << Buffer[i] << " ";
	}

	if (i == _N) {
		std::cout << std::endl;
	}

	if (sortName != "") {
		std::cout << std::endl;
	}
}


int main() {

	Initialize_Buffer(N);
	Show_Buffer(N, "Initializatin");
	
	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	BubbleSort(Buffer, N);
	Show_Buffer(N, "After Sort", "Bubble");

	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	SelectSort(Buffer, N);
	Show_Buffer(N, "After Sort", "Selection");

	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	InsertSort(Buffer, N);
	Show_Buffer(N, "After Sort", "Insertion");

	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	MergeSort(Buffer, 0, N - 1, N);
	Show_Buffer(N, "After Sort", "Merge");

	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	QuickSort(Buffer, 0, N - 1);
	Show_Buffer(N, "After Sort", "Quick");

	Mix_Buffer(MIXCOUNT, N);
	Show_Buffer(N, "After Mix");

	Heap heap(N, true);	// minheap
	
	cout << "Push to Heap" << endl;
	for (int i = 0; i < N; i++) {
		cout << Buffer[i] << " ";
		heap.PushHeap(Buffer[i]);
	}
	cout << endl;

	cout << "Pop from heap" << endl;
	for (int i = 0; i < N; i++) {
		cout << heap.PopHeap() << " ";
	}
	cout << endl;

	Uninitialize_Buffer();

	getchar();
	return 0;
}