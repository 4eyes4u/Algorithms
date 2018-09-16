/*
    Name: Gaussian elimination for solving system with N variables and linear equations

    Time complexity: O(min(N, M) * N * M)
    Space complexity: O(N * M)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 10;
const int INF = 1e9;
const double EPS = 1e-6;

double eqs[N][N], sol[N];
int pos[N];

int gaussian_eleminiation(int n) {
    /*
        Returns the number of solutions: 0, 1, or infinity.
        In case solution exists, it's in array 'sol'.
    */

    bool infinite = false;
    int row = 1, col = 1;

    for (; row <= n && col <= n; col++) {
        int pivot = row;
        for (int i = row; i <= n; i++) 
            if (abs(eqs[i][col]) > abs(eqs[pivot][col]))
                pivot = i;

        if (abs(eqs[pivot][col]) < EPS) {
            infinite = true;
            continue;
        }

        for (int i = 1; i <= n + 1; i++)
            swap(eqs[row][i], eqs[pivot][i]);

        pos[col] = row;

        double d = eqs[row][col];
        for (int i = 1; i <= n + 1; i++)
            eqs[row][i] /= d;

        for (int i = 1; i <= n; i++) {
            if (i == row) 
                continue;

            d = eqs[i][col];
            for (int j = 1; j <= n + 1; j++)
                eqs[i][j] -= eqs[row][j] * d;
        }

        row++;
    }

    for (int i = 1; i <= n; i++)
        if (pos[i] != 0)
            sol[i] = eqs[pos[i]][n + 1];
        else
            sol[i] = 0;

    for (int i = 1; i <= n; i++) {
        double sum = 0;

        for (int j = 1; j <= n; j++)
            sum += sol[j] * eqs[i][j];

        if (abs(sum - eqs[i][n + 1]) > EPS)
            return 0;
    }

    if (infinite)
        return INF;

    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n + 1; j++)
            scanf("%lf", &eqs[i][j]);

    if (gaussian_eleminiation(n) == 1) {
        for (int i = 1; i <= n; i++) {
            sol[i] = floor(sol[i] + 0.5);
            printf("%.0lf ", sol[i]);
        }
    }

    return 0;
}