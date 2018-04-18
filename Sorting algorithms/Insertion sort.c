#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void insertion_sort(int *a, int l, int r) {
    if (r - l <= 1) return;

    for (int i = l; i < r; i++) {
        int tmp = a[i], j = i - 1;

        while (j >= 0 && a[j] > tmp)
            a[j + 1] = a[j--];

        a[j + 1] = tmp;
    }
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);

    insertion_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}