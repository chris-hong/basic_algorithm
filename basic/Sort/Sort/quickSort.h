#pragma once

#include "utils.h"

// Quick Sort는 최종적으로 Pivot으로 정한 숫자기준으로 왼쪽에는 작은 수, 오른쪽에는 큰 수를 두는 작업의 반복
// ## 명심 ## 진행과정에서 front와 back 사이에는 Pivot보다 큰 숫자들이 위치함.
// 따라서 pivot과 비교해서 작은 숫자가 발견되면 (back + 1)<- pivot보다 큰 숫자와 방금 찾은 작은 숫자의 위치를 바꾸어 버림. 
// 마지막으로 Pivot과 back의 SWAP으로 자기위치 찾아주기가 목표

int Partition(int buf[], int left, int right) {
	int pivot = left;		// pivot은 left로 설정
	int front = left + 1;	// front는 전체를 순회하며 값 비교를 할 포인터
	int back = left;		// back은 뒤따라오는 포인터(Partition 포인트)
	
	// 로직은 단순.
	// front가 전체를 순회하면서 pivot과 값 비교
	for (; front <= right; front++) {
		// pivot보다 크면 Pass,
		// pivot보다 작은 것 발견하면 자리확보(back++)후 front와 back 자리변경
		// ==> 나중에 back이 Partition 포인트이므로, pivot보다 작은 값을 pivot의 왼쪽에 배치시키는 효과를 냄
		if (buf[front] < buf[pivot]) {
			back++;
			Swap(buf, front, back);
		}
	}

	Swap(buf, left, back);	// pivot을 partition 포인트로 배치

	return back;
}

void QuickSort(int buf[], int left, int right) {
	if (left < right) {
		int pivot = Partition(buf, left, right);
		QuickSort(buf, left, pivot - 1);
		QuickSort(buf, pivot + 1, right);
	}
}