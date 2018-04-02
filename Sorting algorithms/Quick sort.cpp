#include <cstdio>
#include <utility>
using namespace std;

void q_sort(int *a, int l, int r) {
    if (l == r) return;
    
    int pivot = a[l], k = l;
    for (int i = l + 1; i < r; i++)
        if (a[i] < pivot) {
            swap(a[i], a[k++]);
            swap(a[k], a[i]);
        }

    q_sort(a, l, k);
    q_sort(a, k + 1, r);
}

int main() {
    int a[] = {1, 8, 9, 3, 2, 4, 7, 6, 5, 0};
    int n = sizeof(a) / sizeof(int);

    q_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

    return 0;
}