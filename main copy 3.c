#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_parentheses(int s[][5], int i, int j) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    print_parentheses(s, i, s[i][j]);
    print_parentheses(s, s[i][j] + 1, j);
    printf(")");
}

int matrixmin(int p[], int n) {
    int m[n][n];
    int s[n][n];
    memset(m, 0, sizeof(m[0][0]) * n * n);

    int i, j, k, L, q;

    for (L = 2; L < n; L++) {
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("m Table:\n");
    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    printf("s Table:\n");
    for (i = 1; i < n - 1; i++) {
        for (j = 2; j < n; j++) {
            if (i < j) {
                printf("%d ", s[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("Optimal Parentheses: ");
    print_parentheses(s, 1, n - 1);
    printf("\n");

    return m[1][n - 1];
}

int main() {
    int arr[] = {5, 4, 6, 2, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Minimum cost is %d\n", matrixmin(arr, size));

    return 0;
}