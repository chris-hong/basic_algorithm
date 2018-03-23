#include <iostream>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

int _N = 5;
int _R = 5;
vector<vector<int>> buffer(_N, vector<int>(_R));

enum CATEGORY { COUNTRY, COLOR, BEVERAGE, CIGARETTE, PET };
enum eCOUNTRY { ENGLAND, GERMANY, SWEDEN, NORWAY, DENMARK };
enum eCOLOR { RED, GREEN, BLUE, YELLOW, WHITE };
enum eBEVERAGE { TEA, WATER, MILK, COFFEE, BEER };
enum eCIGARETTE { BLEND, DUNHILL, BLUEMASTER, PALLMALL, PRINCE };
enum ePET { DOG, CAT, HORSE, ZEBRA, BIRD };

bool Check_Einstein_Rule(vector<vector<int>>& buf) {
	
	// 1
	if (buf[COUNTRY][ENGLAND] != buf[COLOR][RED]) return false;

	// 2
	if (buf[COUNTRY][SWEDEN] != buf[PET][DOG]) return false;

	// 3
	if (buf[COUNTRY][DENMARK] != buf[BEVERAGE][TEA]) return false;

	// 4
	if (buf[COLOR][GREEN] != buf[COLOR][WHITE] - 1) return false;

	// 5
	if (buf[COLOR][GREEN] != buf[BEVERAGE][COFFEE]) return false;

	// 6
	if (buf[CIGARETTE][PALLMALL] != buf[PET][BIRD]) return false;

	// 7
	if (buf[COLOR][YELLOW] != buf[CIGARETTE][DUNHILL]) return false;

	// 8
	if (buf[BEVERAGE][MILK] != 2) return false;

	// 9
	if (buf[COUNTRY][NORWAY] != 0) return false;

	// 10
	if (abs(buf[CIGARETTE][BLEND] - buf[PET][CAT]) != 1) return false;

	// 11
	if (abs(buf[PET][HORSE] - buf[CIGARETTE][DUNHILL]) != 1) return false;

	// 12
	if (buf[CIGARETTE][BLUEMASTER] != buf[BEVERAGE][BEER]) return false;

	// 13
	if (buf[COUNTRY][GERMANY] != buf[CIGARETTE][PRINCE]) return false;

	// 14
	if (abs(buf[COUNTRY][NORWAY] - buf[COLOR][BLUE]) != 1) return false;
	
	// 15
	if (abs(buf[CIGARETTE][BLEND] - buf[BEVERAGE][WATER]) != 1) return false;
	
	return true;
}

bool Check_Einstein_Rule_Advanced(vector<vector<int>>& buf, int level) {
	
	// check COUNTRY
	if (level == 0) {
		// 9
		if (buf[COUNTRY][NORWAY] != 0) return false;
	} 
	// check COUNTRY COLOR
	else if (level == 1) {
		// 1
		if (buf[COUNTRY][ENGLAND] != buf[COLOR][RED]) return false;
		// 4
		if (buf[COLOR][GREEN] != buf[COLOR][WHITE] - 1) return false;
		// 14
		if (abs(buf[COUNTRY][NORWAY] - buf[COLOR][BLUE]) != 1) return false;
	}
	// check COUNTRY COLOR BEVERAGE 
	else if (level == 2) {
		// 3
		if (buf[COUNTRY][DENMARK] != buf[BEVERAGE][TEA]) return false;
		// 5
		if (buf[COLOR][GREEN] != buf[BEVERAGE][COFFEE]) return false;
		// 8
		if (buf[BEVERAGE][MILK] != 2) return false;
	}
	// check COUNTRY COLOR BEVERAGE CIGARETTE
	else if (level == 3) {
		// 7
		if (buf[COLOR][YELLOW] != buf[CIGARETTE][DUNHILL]) return false;
		// 12
		if (buf[CIGARETTE][BLUEMASTER] != buf[BEVERAGE][BEER]) return false;
		// 13
		if (buf[COUNTRY][GERMANY] != buf[CIGARETTE][PRINCE]) return false;
		// 15
		if (abs(buf[CIGARETTE][BLEND] - buf[BEVERAGE][WATER]) != 1) return false;
	}
	// check COUNTRY COLOR BEVERAGE CIGARETTE PET
	else {
		// 2
		if (buf[COUNTRY][SWEDEN] != buf[PET][DOG]) return false;
		// 6
		if (buf[CIGARETTE][PALLMALL] != buf[PET][BIRD]) return false;
		// 10
		if (abs(buf[CIGARETTE][BLEND] - buf[PET][CAT]) != 1) return false;
		// 11
		if (abs(buf[PET][HORSE] - buf[CIGARETTE][DUNHILL]) != 1) return false;
	}

	return true;
}

void Swap_Buffer(vector<vector<int>>& buf, int category, int i, int j) {
	int temp = buf[category][i];
	buf[category][i] = buf[category][j];
	buf[category][j] = temp;
}

void Print_Einstein(vector<vector<int>>& buf, int N, int R) {
	for (int i = 0; i < R; i++) {
		if (buf[COUNTRY][i] == buf[PET][ZEBRA]) {
			cout << "HIT: " << i << endl;
			break;
		}
	}
}

static int COUNTER = 0;

void Permutaion_Einstein(vector<vector<int>>& buf, int category, int len, int N, int R) {
	if (category == N) {
		Print_Einstein(buf, N, R);
		return;
	}

	if (len == R) {
		if (Check_Einstein_Rule_Advanced(buf, category)) {
			Permutaion_Einstein(buf, category + 1, 0, N, R);
		}
		
		return;
	}

	for (int i = len; i < R; i++) {
		Swap_Buffer(buf, category, i, len);
		Permutaion_Einstein(buf, category, len + 1, N, R);
		Swap_Buffer(buf, category, i, len);
	}
}


int main() {

	for (int i = 0; i < _N; i++) {
		for (int j = 0; j < _R; j++) {
			buffer[i][j] = j;
		}
	}

	Permutaion_Einstein(buffer, 0, 0, _N, _R);

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << buffer[i][j] << endl;
		}
	}*/


	getchar();
	return 0;
}
