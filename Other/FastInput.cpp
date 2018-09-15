/*
    Name: Fast input
*/

#include <bits/stdc++.h>
using namespace std;

int read_int() {
    int ret = 0, sign = 1;
    char c;
    
    do {
        c = getchar();
    } while (c != '-' && (c < '0' || c > '9'));
    
    if (c == '-') sign = -1;
    else ret = c - '0';
    
    for (c = getchar(); ; c = getchar()) {
        if (c < '0' || c > '9') break;
        ret = 10 * ret + (c - '0');
    }
    
    return ret * sign;
}

int main() {
    int n = read_int();
    vector<int> v;

    while (n--) {
        int x = read_int();
        v.push_back(x);
    }

    for (auto x: v) cout << x << endl;

    return 0;
}
