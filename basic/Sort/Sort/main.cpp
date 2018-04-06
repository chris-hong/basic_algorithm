#include <iostream>
#include <vector>
#include <random>
#include <string>

#include "sort.h"
#include "heap.h"
#include "heap2.h"

int _N = 10;
std::vector<int> Buffer(_N);

void Initialize_Buffer() {
	for (int i = 0; i < _N; i++) {
		Buffer[i] = i + 1;
	}
}

void Mix_Buffer(int count) {
	std::random_device rn;
	std::mt19937_64 rnd(rn());
	std::uniform_int_distribution<int> range(0, _N - 1);

	for (int i = 0; i < count; i++) {
		int pIdx = range(rnd);
		int nIdx = range(rnd);
		int temp = Buffer[pIdx];
		Buffer[pIdx] = Buffer[nIdx];
		Buffer[nIdx] = temp;
	}
	
}

void Show_Buffer(std::string desc, std::string sortName = "") {
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

	/*Initialize_Buffer();
	Show_Buffer("Initializatin");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	BubbleSort(Buffer, _N);
	Show_Buffer("After Sort", "Bubble");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	SelectSort(Buffer, _N);
	Show_Buffer("After Sort", "Selection");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	InsertSort(Buffer, _N);
	Show_Buffer("After Sort", "Insertion");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	MergeSort(Buffer, 0, _N - 1);
	Show_Buffer("After Sort", "Merge");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	QuickSort(Buffer, 0, _N - 1);
	Show_Buffer("After Sort", "Quick");

	Mix_Buffer(100);
	Show_Buffer("After Mix");

	Heap heap(_N);
	heap.MakeHeap(Buffer, _N);
	std::cout << std::endl << "=== [ After Inserting Heap ] ===" << std::endl;
	heap.PrintHeap(_N);
	
	heap.HeapSort();
	std::cout << std::endl << "=== [ After Heap Sort ] ===" << std::endl;
	heap.PrintHeap(_N);*/

	Heap2 heap2(_N, true);	// minheap
	heap2.PushHeap(3);
	heap2.PushHeap(2);
	heap2.PushHeap(1);
	heap2.PushHeap(4);
	heap2.PushHeap(6);
	heap2.PushHeap(5);
	heap2.PushHeap(7);
	heap2.PushHeap(10);
	heap2.PushHeap(9);
	heap2.PushHeap(8);
	heap2.PushHeap(11);

	heap2.PrintNode();

	for (int i = 0; i < 11; i++) {
		cout << "POP[" << i << "]: " << heap2.PopHeap() << endl;
		heap2.PrintNode();
		getchar();
	}

	getchar();
	return 0;
}