#pragma once

#include <vector>

#include "Util.h"

void Swap_Buffer(std::vector<int>& buf, int i, int j) {
	int temp = buf[i];
	buf[i] = buf[j];
	buf[j] = temp;
}

// 순열 (0 - Base)
void Permutation(std::vector<int>& buf, int depth, int N, int R) {
	if (depth == R) {
		Print_Buffer(buf, depth);
		return;
	}

	for (int i = depth; i < N; i++) {
		Swap_Buffer(buf, i, depth);
		Permutation(buf, depth + 1, N, R);
		Swap_Buffer(buf, i, depth);
	}

}

// 중복 순열 (0 - Base)
void Repeated_Permutation(std::vector<int>& buf, int depth, int N, int R) {

	if (depth == R) {
		Print_Buffer(buf, depth);
		return;
	}

	for (int i = 0; i = N; i++) {
		buf[depth] = i;
		Repeated_Permutation(buf, depth + 1, N, R);
	}
}

void Right_Rotate(std::vector<int>& buf, int start, int end) {
	int last = buf[end];
	for (int i = end; i > start; i--) {
		buf[i] = buf[i - 1];
	}
	buf[start] = last;
}

void Left_Rotate(std::vector<int>& buf, int start, int end) {
	int first = buf[start];
	for (int i = start; i < end; i++) {
		buf[i] = buf[i + 1];
	}
	buf[end] = first;
}

// 사전 순열 (0 - Base)
void Dictionary_Permutation(std::vector<int>& buf, int depth, int N, int R) {

	if (depth == R) {
		Print_Buffer(buf, depth);
		return;
	}

	for (int i = depth; i < N; i++) {
		Right_Rotate(buf, depth, i);
		Dictionary_Permutation(buf, depth + 1, N, R);
		Left_Rotate(buf, depth, i);
	}
}