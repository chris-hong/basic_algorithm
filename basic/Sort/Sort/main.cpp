#include <iostream>
#include <vector>
#include <random>
#include <string>

#include "sort.h"
#include "heap.h"

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

	Heap heap(_N, true);	// minheap
	heap.PushHeap(3);
	heap.PushHeap(2);
	heap.PushHeap(1);
	heap.PushHeap(4);
	heap.PushHeap(6);
	heap.PushHeap(5);
	heap.PushHeap(7);
	heap.PushHeap(10);
	heap.PushHeap(9);
	heap.PushHeap(8);
	heap.PushHeap(11);

	heap.PrintNode();

	for (int i = 0; i < 11; i++) {
		cout << "POP[" << i << "]: " << heap.PopHeap() << endl;
		heap.PrintNode();
		getchar();
	}

	getchar();
	return 0;
}