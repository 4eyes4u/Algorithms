#include <stdio.h>
#include <stdlib.h>

void shell_sort(int *a, int l, int r) {
    for (int gap = (r - l) / 2; gap; gap >>= 1)
        for (int i = l; i < r; i += gap) {
            int tmp = a[i], j = i - 1;

            while (j >= l && a[j] > tmp) a[j + 1] = a[j--];
            
            a[j + 1] = tmp;
        }
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);

    shell_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    puts("");

    return 0;
}
