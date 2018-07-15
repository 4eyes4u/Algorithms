#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
const double pi = acos(-1.0);

void dft(vector<base> &a, int inv) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) { // flipping bits (because of butterfly operation)
        int bit = n >> 1;
        for (; bit & j; bit >>= 1) j ^= bit;
        j ^= bit;

        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        base wn = polar(1.0, 2.0 * pi / len * (inv ? -1.0 : 1.0));

        for (int i = 0; i < n; i += len) {
            base w = polar(1.0, 0.0);

            for (int j = 0; j < len / 2; j++) {
                base t = a[i + j + len / 2] * w; // multiplying by w only once
                a[i + j + len / 2] = a[i + j] - t;
                a[i + j] += t;

                w *= wn;
            }
        }
    }

    if (inv)
        for (auto &x: a) x /= n;
}

vector<int> convolute(vector<int> &a, vector<int> &b) {
    int n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;

    vector<int> c(n, 0);
    vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    fa.resize(n), fb.resize(n);

    dft(fa, 0);
    dft(fb, 0);
    for (int i = 0; i < n; i++) fa[i] *= fb[i];

    dft(fa, 1);
    for (int i = 0; i < n; i++) c[i] = round(fa[i].real());

    while (c.size() && !c.back()) c.pop_back(); // we can remove t(r)ailing zeroes
    return c;
}

void eval(vector<int> &c) { // normalization of number
    int carry = 0;

    for (int i = 0; i < c.size(); i++) {
        c[i] += carry;
        carry = c[i] / 10;
        c[i] %= 10;
    }

    reverse(c.begin(), c.end());
}

vector<int> fast_pow(vector<int> &a, int k) { // calculating [P(x)] ^ k
    vector<int> ret = {1};

    while (k) {
        if (k & 1) ret = convolute(a, ret);
        k >>= 1;
        a = convolute(a, a);
    }

    return ret;
}

int main() {
    string s;
    cin >> s;
    vector<int> v(s.length());

    // transforming array of chars to array of ints
    transform(s.begin(), s.end(), v.rbegin(), [](char c) -> int { return atoi(&c); });

    int k;
    cin >> k;
    v = fast_pow(v, k);
    
    eval(v);
    for (auto x: v) cout << x;
    cout << endl;

    return 0;
}
