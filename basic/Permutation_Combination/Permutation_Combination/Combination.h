#pragma once

#include <vector>

#include "Util.h"

// 조합 (0 - Base)
void Combination(std::vector<int>& buf, int depth, int N, int R, int idx) {
	if (depth == R) {
		Print_Buffer(buf, depth);
		return;
	}
	if (idx == N) {
		return;
	}

	buf[depth] = idx;

	Combination(buf, depth + 1, N, R, idx + 1);

	Combination(buf, depth, N, R, idx + 1);
}

// 중복 조합 (0 - Base)
void Repeated_Combination(std::vector<int>& buf, int depth, int N, int R, int idx) {
	if (depth == R) {
		Print_Buffer(buf, depth);
		return;
	}
	if (idx == N) {
		return;
	}

	buf[depth] = idx;

	Repeated_Combination(buf, depth + 1, N, R, idx);

	Repeated_Combination(buf, depth, N, R, idx + 1);
}