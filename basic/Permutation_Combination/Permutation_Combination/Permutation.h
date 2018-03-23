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