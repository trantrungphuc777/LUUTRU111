#include <stdio.h>

int main() {
    int n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];

    printf("Nhap cac phan tu cua mang:\n");
    for (i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int x;
    printf("Nhap x: ");
    scanf("%d", &x);

    printf("Gia tri phan tu thu %d la: %d\n", x, arr[x - 1]);

    int max = arr[0];
    int max_index = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }
    printf("Vi tri max: %d, gia tri max: %d\n", max_index + 1, max);

    int min = arr[0];
    
    int min_index = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            min_index = i;
        }
    }
    printf("Vi tri min: %d, gia tri min: %d\n", min_index + 1, min);

    printf("Cac so le trong mang: ");
    for (i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Tong gia tri cua cac phan tu trong mang: %d\n", sum);

    return 0;
}
