#pragma once
#include <iostream>
using namespace std;

class Heap {
public:
	Heap(bool bMinHeap, int capacity);
	~Heap();
	void Push(int num);
	int Pop();
	int GetSize();
	void PrintBuffer();

private:
	bool m_bMinHeap;
	int mCapacity;
	int mSize;
	int* m_pBuffer;

	int getParentIdx(int idx);
	int getLeftChildIdx(int idx);
	int getRightChildIdx(int idx);
	void heapUp(int idx);
	void heapDown(int idx);
	void resizeHeap();
	void swap(int idx1, int idx2);
};

Heap::Heap(bool bMinHeap, int capacity) {
	m_bMinHeap = bMinHeap;
	mCapacity = capacity;
	mSize = 0;
	m_pBuffer = new int[mCapacity];
	for (int i = 0; i < mCapacity; i++) m_pBuffer[i] = INT32_MIN;
}

Heap::~Heap() {
	delete[] m_pBuffer;
}

void Heap::Push(int num) {
	if (mSize == mCapacity) resizeHeap();	// 크기가 Max이면 2배로 크기 조정

	m_pBuffer[mSize] = num;
	heapUp(mSize);
	mSize += 1;
}

int Heap::Pop() {
	if (mSize == 0) return INT32_MIN;

	int ret = m_pBuffer[0];
	mSize -= 1;
	m_pBuffer[0] = m_pBuffer[mSize];
	m_pBuffer[mSize] = INT32_MIN;
	heapDown(0);
	
	return ret;
}

int Heap::GetSize() {
	return mSize;
}

void Heap::PrintBuffer() {
	cout << "[PRINT START]" << endl;
	for (int i = 0; i < mSize; i++) {
		cout << "[" << i << "]: " << m_pBuffer[i] << endl;
	}
	cout << "[PRINT END]" << endl << endl;
}

int Heap::getParentIdx(int idx) {
	if (idx < 1) return INT32_MIN;
	return (idx - 1) / 2;
}

int Heap::getLeftChildIdx(int idx) {
	if (idx * 2 + 1 >= mSize) return INT32_MIN;
	return idx * 2 + 1;
}

int Heap::getRightChildIdx(int idx) {
	if (idx * 2 + 2 >= mSize) return INT32_MIN;
	return idx * 2 + 2;
}

void Heap::heapUp(int idx) {
	int parentIdx = getParentIdx(idx);
	
	if (parentIdx == INT32_MIN) return;		// 재귀함수 종료조건
	
	if (m_bMinHeap && m_pBuffer[idx] < m_pBuffer[parentIdx]) {
		swap(idx, parentIdx);
		heapUp(parentIdx);
	}
	
	if (!m_bMinHeap && m_pBuffer[idx] > m_pBuffer[parentIdx]) {
		swap(idx, parentIdx);
		heapUp(parentIdx);
	}
}

void Heap::heapDown(int idx) {
	int leftChildIdx = getLeftChildIdx(idx);
	int rightChildIdx = getRightChildIdx(idx);

	if (leftChildIdx == INT32_MIN && rightChildIdx == INT32_MIN) return;	// 재귀함수 종료조건

	int compIdx = idx;

	if (leftChildIdx > INT32_MIN) {
		if (m_bMinHeap && m_pBuffer[leftChildIdx] < m_pBuffer[compIdx]) compIdx = leftChildIdx;
		if (!m_bMinHeap && m_pBuffer[leftChildIdx] > m_pBuffer[compIdx]) compIdx = leftChildIdx;
	}

	if (rightChildIdx > INT32_MIN) {
		if (m_bMinHeap && m_pBuffer[rightChildIdx] < m_pBuffer[compIdx]) compIdx = rightChildIdx;
		if (!m_bMinHeap && m_pBuffer[rightChildIdx] > m_pBuffer[compIdx]) compIdx = rightChildIdx;
	}

	if (compIdx != idx) {
		swap(compIdx, idx);
		heapDown(compIdx);
	}
}

void Heap::resizeHeap() {
	int capacity = 2 * mCapacity;
	int* pTemp = new int[capacity];

	for (int i = 0; i < capacity; i++) pTemp[i] = INT32_MIN;
	for (int i = 0; i < mCapacity; i++) pTemp[i] = m_pBuffer[i];

	delete[] m_pBuffer;
	mCapacity = capacity;
	m_pBuffer = pTemp;
}

void Heap::swap(int idx1, int idx2) {
	int temp = m_pBuffer[idx1];
	m_pBuffer[idx1] = m_pBuffer[idx2];
	m_pBuffer[idx2] = temp;
}