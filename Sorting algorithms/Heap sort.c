#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

int find_min(int *h) { return h[1]; }

int delete_min(int *h, int *size) {
    h[1] = h[*size];

    for (int i = 1; 2 * i <= *size; ) {
        int j = 2 * i;
        if (2 * i + 1 <= *size && h[2 * i + 1] < h[2 * i]) j++;

        if (h[i] > h[j]) {
            swap(h + i, h + j);
            i = j;
        }
        else break;
    }
}

void insert(int *h, int *size, int x) {
    h[++(*size)] = x;

    for (int i = *size; i >= 2; i /= 2) {
        if (h[i] < h[i / 2]) swap(h + i, h + i / 2);
        else break;
    }
}

void heap_sort(int *a, int l, int r) {
    if (r - l <= 1) return;
    int *h = (int *)calloc(r - l, sizeof(int)), size = 0;

    for (int i = l; i < r; i++) insert(h, &size, a[i]);
    for (int i = l; i < r; i++) {
        a[i] = find_min(h);
        delete_min(h, &size);
    }
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);

    heap_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}