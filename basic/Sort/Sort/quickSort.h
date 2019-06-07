#pragma once

#include "utils.h"

// Quick Sort�� ���������� Pivot���� ���� ���ڱ������� ���ʿ��� ���� ��, �����ʿ��� ū ���� �δ� �۾��� �ݺ�
// ## ��� ## ����������� front�� back ���̿��� Pivot���� ū ���ڵ��� ��ġ��.
// ���� pivot�� ���ؼ� ���� ���ڰ� �߰ߵǸ� (back + 1)<- pivot���� ū ���ڿ� ��� ã�� ���� ������ ��ġ�� �ٲپ� ����. 
// ���������� Pivot�� back�� SWAP���� �ڱ���ġ ã���ֱⰡ ��ǥ

int Partition(int buf[], int left, int right) {
	int pivot = left;		// pivot�� left�� ����
	int front = left + 1;	// front�� ��ü�� ��ȸ�ϸ� �� �񱳸� �� ������
	int back = left;		// back�� �ڵ������ ������(Partition ����Ʈ)
	
	// ������ �ܼ�.
	// front�� ��ü�� ��ȸ�ϸ鼭 pivot�� �� ��
	for (; front <= right; front++) {
		// pivot���� ũ�� Pass,
		// pivot���� ���� �� �߰��ϸ� �ڸ�Ȯ��(back++)�� front�� back �ڸ�����
		// ==> ���߿� back�� Partition ����Ʈ�̹Ƿ�, pivot���� ���� ���� pivot�� ���ʿ� ��ġ��Ű�� ȿ���� ��
		if (buf[front] < buf[pivot]) {
			back++;
			Swap(buf, front, back);
		}
	}

	Swap(buf, left, back);	// pivot�� partition ����Ʈ�� ��ġ

	return back;
}

void QuickSort(int buf[], int left, int right) {
	if (left < right) {
		int pivot = Partition(buf, left, right);
		QuickSort(buf, left, pivot - 1);
		QuickSort(buf, pivot + 1, right);
	}
}