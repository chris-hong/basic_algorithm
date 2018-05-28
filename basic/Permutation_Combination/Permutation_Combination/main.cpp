#include <iostream>
#include <vector>

#include "Permutation.h"
#include "Combination.h"

int _N = 6;
int _R = 6;

std::vector<int> buffer(_R);
std::vector<int> pBuffer(_N);

void Make_PBuffer(std::vector<int>& buf, int N) {
	for (int i = 0; i < N; i++) {
		buf[i] = i;
	}
}

int main() {

	//Combination(buffer, 0, _N, _R, 0);

	//Repeated_Combination(buffer, 0, _N, _R, 0);

	Make_PBuffer(pBuffer, _N);
	//Permutation(pBuffer, 0, _N, _R);
	Dictionary_Permutation(pBuffer, 0, _N, _R);

	//Repeated_Permutation(buffer, 0, _N, _R);

	getchar();
	return 0;
}