#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    printf("Mang sau khi sap xep chen:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int arr[1000];

    do {
        printf("Nhap so luong phan tu cua mang (0 < n < 1000): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 1000);

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);
    printArray(arr, n);

    printf("\nPhan tich do phuc tap thuat toan:\n");
    printf("- Thoi gian tot nhat (mang da sap xep): O(n)\n");
    printf("- Thoi gian trung binh: O(n^2)\n");
    printf("- Thoi gian toi xau (mang sap xep nguoc): O(n^2)\n");

    return 0;
}
