#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int DIM = 50 + 5;

struct Matrix {
    int a[DIM][DIM];

    int *operator [] (int r) {
        return a[r];
    }

    Matrix (int x = 0) {
        memset(a, 0, sizeof(a));
        if (x) for (int i = 0; i < DIM; i++) a[i][i] = x;
    }
} const I(1);

Matrix operator + (Matrix A, Matrix B) {
    Matrix C;

    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            C[i][j] = (A[i][j] + B[i][j]) % mod;

    return C;
}

Matrix operator * (Matrix A, Matrix B) {
    Matrix C;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            long long entry = 0;
            
            for (int k = 0; k < DIM; k++) {
                entry += (A[i][k] * B[k][j]) % mod;
                if (entry > mod) entry -= mod;
            }

            C[i][j] = entry;
        }
    }

    return C;
}

Matrix operator ^ (Matrix A, long long n) {
    Matrix C = I;

    while (n) {
        if (n & 1) C = C * A;
        n >>= 1;
        A = A * A;
    }

    return C;
}

int main() {
    return 0;
}