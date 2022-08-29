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