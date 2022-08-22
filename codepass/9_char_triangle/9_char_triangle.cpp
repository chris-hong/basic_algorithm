#include <stdio.h>

int main()
{
    int i, j, k;

    int N;
    scanf("%d", &N);

    if (N % 2 == 0 || N < 1 || N > 100) {
        printf("INPUT ERROR");
        return 0;
    }

    int arr[100][100];

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }

    char a = 'A';

    for (i = N / 2; i >= 0; i--) {
        for (j = i; j < N - i; j++) {
            arr[j][i] = a++;
            if (a == 'Z' + 1)a = 'A';
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (arr[i][j] == 0)printf(" ");
            else printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}



//#include <iostream>
//#include <cstdio>
////#include <cstring>
//
//using namespace std;
//
//bool check_input(int input)
//{
//	if (input < 1 || input % 2 == 0)
//	{
//		cout << "INPUT ERROR!" << endl;
//		return true;
//	}
//	return false;
//}
//
//void print_triangle(int input)
//{
//	int arr[100][100];
//
//	//memset(arr, -1, sizeof(int) * 100 * 100);
//
//	for (int i = 0; i < 100; i++)
//	{
//		for (int j = 0; j < 100; j++)
//			arr[i][j] = -1;
//	}
//
//	int center = input / 2;
//	int num = 0;
//
//	for (int j = center; j >= 0; j--)
//	{
//		int end = center + (center - j);
//		for (int i = j; i <= end; i++) {
//			arr[i][j] = num++;
//		}
//	}
//
//	for (int k = 0; k < input; k++)
//	{
//		for (int l = 0; l < input; l++)
//		{
//			if (arr[k][l] >= 0) printf("%c ", (arr[k][l] % 26) + 65);
//			else break;
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		cin >> input;
//	} while (check_input(input));
//
//	print_triangle(input);
//
//	return 0;
//}