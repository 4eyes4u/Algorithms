#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void selection_sort(int *a, int l, int r) {
    if (r - l <= 1) return;

    for (int i = l; i < r; i++) {
        int idx = i;

        for (int j = i + 1; j < r; j++)
            if (a[j] < a[idx])
                idx = j;

        swap(a + i, a + idx);
    }
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);

    selection_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}