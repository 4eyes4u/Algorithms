#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int *a, int l, int r, int *aux) {
    if (r - l <= 1) return;

    int half = l + (r - l) / 2;
    merge_sort(a, l, half, aux);
    merge_sort(a, half, r, aux);

    for (int i = 0, j = l, k = half; i < r - l; i++) {
        if (j < half && k < r) {
            if (a[j] < a[k]) aux[i] = a[j++];
            else aux[i] = a[k++];
        }
        else if (j < half) aux[i] = a[j++];
        else aux[i] = a[k++];
    }

    memcpy(a + l, aux, (r - l) * sizeof(int));
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);
    int *b = (int *)calloc(n, sizeof(int));

    merge_sort(a, 0, n, b);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}