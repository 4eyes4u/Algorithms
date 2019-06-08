/*
    Name: Linear sieve (Gries-Misra sieve)

    Time complexity: O(N)
    Space complexity: O(N)
*/

#include <iostream>
#include <vector>

std::vector<int> sieve(int bound) {
    std::vector<int> low(bound + 1), primes;

    for (int i = 2; i <= bound; i++) {
        if (low[i] == 0) {
            low[i] = i;
            primes.emplace_back(i);
        }

        for (int j = 0; j < (int)primes.size() &&
                            primes[j] <= low[i] &&
                            i * primes[j] <= bound; j++) {
            
            low[i * primes[j]] = primes[j];
        }
    }

    return primes;
}

int main() {
    int bound;
    std::cin >> bound;

    auto primes = sieve(bound);
    for (const int &prime : primes)
        std::cout << prime << std::endl;

    return 0;
}