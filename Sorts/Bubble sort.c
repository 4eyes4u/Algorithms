#include <stdio.h>

void swap(int *a, int *b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void bubble_sort(int *a, int l, int r) {
	int flag = 0;
	
	do {
		flag = 0;
		
		for (int i = l + 1; i < r; i++)
			if (a[i] < a[i - 1]) {
				swap(a + i, a + i - 1);
				flag = 1;
			}
	} while(flag);
}

int main() {
    int a[] = {7, 1, 2, 8, 3, 6, 5, 4};
    int n = sizeof(a) / sizeof(int);
    
    bubble_sort(a, 0, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);

	return 0;
}
