#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void bubble_sort(int *a, int l, int r) {
    for (int i = l; i < r; i++)
        for (int j = i + 1; j < r; j++)
            if (a[i] > a[j])
                swap(a + i , a + j);

}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);

    bubble_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}