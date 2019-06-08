/*
    Name: Chinese remainder theorem (Garne's algorithm)

    Time complexity: O(K^2 * logP)
    Space complexity: O(K^2)

* * *
Can overflow easily.
*/

#include <iostream>
#include <vector>

int extended_euclidean(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        
        return a;
    }

    int x0, y0;
    int d = extended_euclidean(b, a % b, x0, y0);
    x = y0, y = x0 - y0 * (int)(a / b);

    return d;
}

int main() {
    int k;
    std::cin >> k;

    std::vector<int> a(k), p(k);
    for (int i = 0; i < k; i++)
        std::cin >> a[i] >> p[i];
    
    std::vector<std::vector<int>> r(k, std::vector<int>(k, 0)); 
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int spare;
            extended_euclidean(p[i], p[j], r[i][j], spare);
            r[i][j] = (r[i][j] + p[j]) % p[j];
        }
    }

    std::vector<int> x(k);
    for (int i = 0; i < k; i++) {
        x[i] = a[i];
        for (int j = 0; j < i; j++) {
            x[i] = r[j][i] * (x[i] - x[j]);
            x[i] = x[i] % p[i];
            x[i] = (x[i] + p[i]) % p[i];
        }
    }

    long long sol = 0, carry = 1;
    for (int i = 0; i < k; i++) {
        sol += carry * x[i];
        carry *= p[i];
    }

    std::cout << sol << std::endl;

    return 0;
}