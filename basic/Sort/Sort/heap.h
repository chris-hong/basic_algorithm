#pragma once

#include <iostream>

using namespace std;

class Heap {
private:
	int mCapacity;
	int mSize;
	bool bMinHeap;
	int* mNodeList;

	int GetParentIndex(int idx);
	int GetLeftChildIndex(int idx);
	int GetRightChildIndex(int idx);
	void SwapNode(int idx1, int idx2);
	void ResizeHeap();
	void HeapUp(int index);
	void HeapDown(int index);

public:
	Heap(int capacity, bool isMinHeap);
	~Heap();
	void PushHeap(int num);
	int PopHeap();
	void PrintNode();
};

Heap::Heap(int capacity, bool isMinHeap) {
	mCapacity = capacity;
	mSize = 0;
	bMinHeap = isMinHeap;

	mNodeList = new int[mCapacity];
	for (int i = 0; i < mCapacity; i++) {
		mNodeList[i] = -1;
	}
}

Heap::~Heap() {
	if (mNodeList) {
		delete(mNodeList);
	}
}

int Heap::GetParentIndex(int idx) {
	//(idx - 1) /2 
	if (idx <= 0) return -1;
	return (idx - 1) / 2;
}

int Heap::GetLeftChildIndex(int idx) {
	// idx * 2 + 1
	if ((idx * 2) + 1 >= mSize) return -1;
	return (idx * 2) + 1;
}

int Heap::GetRightChildIndex(int idx) {
	// idx * 2 + 2
	if ((idx * 2) + 2 >= mSize) return -1;
	return (idx * 2) + 2;
}

void Heap::SwapNode(int idx1, int idx2) {
	int temp = mNodeList[idx1];
	mNodeList[idx1] = mNodeList[idx2];
	mNodeList[idx2] = temp;
}

void Heap::ResizeHeap() {
	int* temp = mNodeList;
	mNodeList = new int[mCapacity * 2];

	for (int i = 0; i < mCapacity * 2; i++) {
		mNodeList[i] = -1;
	}

	for (int i = 0; i < mCapacity; i++) {
		mNodeList[i] = temp[i];
	}

	mCapacity = mCapacity * 2;

	delete(temp);
}

void Heap::HeapUp(int idx) {
	int parentIdx = GetParentIndex(idx);

	// 부모가 없으면 끝
	if (parentIdx == -1) return;

	// 부모가 나보다 작아야 한다. 
	if (bMinHeap) {
		// 부모가 나보다 크면 바꾼다.
		if (mNodeList[parentIdx] > mNodeList[idx]) {
			SwapNode(idx, parentIdx);
			HeapUp(parentIdx);
		}
	}
	// 부모가 나보다 커야 한다.
	else {
		// 부모가 나보다 작으면 바꾼다.
		if (mNodeList[parentIdx] < mNodeList[idx]) {
			SwapNode(idx, parentIdx);
			HeapUp(parentIdx);
		}
	}
}

void Heap::HeapDown(int idx) {
	int leftChildIdx = GetLeftChildIndex(idx);
	int rightChildIdx = GetRightChildIndex(idx);

	// 자식이 없으면 끝
	if (leftChildIdx == -1 && rightChildIdx == -1) return;

	// 자식이 나보다 커야한다.
	if (bMinHeap) {
		// 자식이 나보다 작으면 바꾼다.
		int min = idx;

		// left 검사
		if (leftChildIdx != -1 && mNodeList[leftChildIdx] < mNodeList[min]) {
			min = leftChildIdx;
		}
		// right 검사
		if (rightChildIdx != -1 && mNodeList[rightChildIdx] < mNodeList[min]) {
			min = rightChildIdx;
		}

		if (min == leftChildIdx || min == rightChildIdx) {
			SwapNode(idx, min);
			HeapDown(min);
		}
	}
	// 자식이 나보다 작아야 한다.
	else {
		// 자식이 나보다 크면 바꾼다.
		int max = idx;

		// left 검사
		if (leftChildIdx != -1 && mNodeList[leftChildIdx] > mNodeList[max]) {
			max = leftChildIdx;
		}
		// rifht 검사
		if (rightChildIdx != -1 && mNodeList[rightChildIdx] > mNodeList[max]) {
			max = rightChildIdx;
		}

		if (max == leftChildIdx || max == rightChildIdx) {
			SwapNode(idx, max);
			HeapDown(max);
		}
	}
}

void Heap::PushHeap(int num) {
	// 공간체크
	if (mSize == mCapacity) {
		cout << "Resize Heap" << endl;
		ResizeHeap();
	}

	// 마지막 위치에 넣는다
	int idx = mSize;
	mNodeList[idx] = num;
	mSize += 1;
	HeapUp(idx);
}

int Heap::PopHeap() {
	if (mSize == 0) {
		cout << "Heap size is 0" << endl;
		return -1;
	}

	int num = mNodeList[0];
	mNodeList[0] = mNodeList[mSize - 1];
	mNodeList[mSize - 1] = -1;
	mSize -= 1;
	HeapDown(0);

	return num;
}

void Heap::PrintNode() {
	for (int i = 0; i < mCapacity; i++) {
		cout << "[" << i << "]: " << mNodeList[i] << endl;
	}
}
