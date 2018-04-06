#pragma once

#include <iostream>

using namespace std;

class Heap2 {
private:
	int mCapacity;
	int mSize;
	bool bMinHeap;
	int* mNode;

	int GetParentIndex(int idx);
	int GetLeftChildIndex(int idx);
	int GetRightChildIndex(int idx);
	void SwapNode(int idx1, int idx2);
	void ResizeHeap();
	void HeapUp(int index);
	void HeapDown(int index);

public:
	//Heap2();
	Heap2(int capacity, bool isMinHeap);
	~Heap2();
	void PushHeap(int num);
	int PopHeap();
	void PrintNode();
};

//Heap2::Heap2() {}

Heap2::Heap2(int capacity, bool isMinHeap) {
	mCapacity = capacity;
	mSize = 0;
	bMinHeap = isMinHeap;

	mNode = new int[mCapacity];
	for (int i = 0; i < mCapacity; i++) {
		mNode[i] = -1;
	}
}

Heap2::~Heap2() {
	if (mNode) {
		delete(mNode);
	}
}

int Heap2::GetParentIndex(int idx) {
	//(idx - 1) /2 
	if (idx <= 0) return -1;
	return (idx - 1) / 2;
}

int Heap2::GetLeftChildIndex(int idx) {
	// idx * 2 + 1
	if ((idx * 2) + 1 >= mSize) return -1;
	return (idx * 2) + 1;
}

int Heap2::GetRightChildIndex(int idx) {
	// idx * 2 + 2
	if ((idx * 2) + 2 >= mSize) return -1;
	return (idx * 2) + 2;
}

void Heap2::SwapNode(int idx1, int idx2) {
	int temp = mNode[idx1];
	mNode[idx1] = mNode[idx2];
	mNode[idx2] = temp;
}

void Heap2::ResizeHeap() {
	int* temp = mNode;
	mNode = new int[mCapacity * 2];
	
	for (int i = 0; i < mCapacity * 2; i++) {
		mNode[i] = -1;
	}

	for (int i = 0; i < mCapacity; i++) {
		mNode[i] = temp[i];
	}

	mCapacity = mCapacity * 2;

	delete(temp);
}

void Heap2::HeapUp(int idx) {
	int parentIdx = GetParentIndex(idx);

	// 부모가 없으면 끝
	if (parentIdx == -1) return;

	// 부모가 나보다 작아야 한다. 
	if (bMinHeap) {
		// 부모가 나보다 크면 바꾼다.
		if (mNode[parentIdx] > mNode[idx]) {
			SwapNode(idx, parentIdx);
			HeapUp(parentIdx);
		}
	}
	// 부모가 나보다 커야 한다.
	else {
		// 부모가 나보다 작으면 바꾼다.
		if (mNode[parentIdx] < mNode[idx]) {
			SwapNode(idx, parentIdx);
			HeapUp(parentIdx);
		}
	}
}

void Heap2::HeapDown(int idx) {
	int leftChildIdx = GetLeftChildIndex(idx);
	int rightChildIdx = GetRightChildIndex(idx);

	// 자식이 없으면 끝
	if (leftChildIdx == -1 && rightChildIdx == -1) return;

	// 자식이 나보다 커야한다.
	if (bMinHeap) {
		// 자식이 나보다 작으면 바꾼다.
		int min = idx;
		
		// left 검사
		if (leftChildIdx != -1 && mNode[leftChildIdx] < mNode[min]) {
			min = leftChildIdx;
		}
		// right 검사
		if (rightChildIdx != -1 && mNode[rightChildIdx] < mNode[min]) {
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
		if (leftChildIdx != -1 && mNode[leftChildIdx] > mNode[max]) {
			max = leftChildIdx;
		}
		// rifht 검사
		if (rightChildIdx != -1 && mNode[rightChildIdx] > mNode[max]) {
			max = rightChildIdx;
		}
		
		if (max == leftChildIdx || max == rightChildIdx) {
			SwapNode(idx, max);
			HeapDown(max);
		}
	}
}

void Heap2::PushHeap(int num) {
	// 공간체크
	if (mSize == mCapacity) {
		cout << "Resize Heap" << endl;
		ResizeHeap();
	}
	
	// 마지막 위치에 넣는다
	int idx = mSize;
	mNode[idx] = num;
	mSize += 1;
	HeapUp(idx);
}

int Heap2::PopHeap() {
	if (mSize == 0) {
		cout << "Heap size is 0" << endl;
		return -1;
	}

	int num = mNode[0];
	mNode[0] = mNode[mSize - 1];
	mNode[mSize - 1] = -1;
	mSize -= 1;
	HeapDown(0);
	
	return num;
}

void Heap2::PrintNode() {
	for (int i = 0; i < mCapacity; i++) {
		cout << "[" << i << "]: " << mNode[i] << endl;
	}
}
