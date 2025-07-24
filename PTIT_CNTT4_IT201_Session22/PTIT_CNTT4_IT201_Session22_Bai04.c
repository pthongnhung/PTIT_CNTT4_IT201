#include <stdio.h>

int main() {
    int n;
    int matrix[100][100];
    int count = 0;

    printf("Nhập số đỉnh (0 < n < 100): ");
    scanf("%d", &n);

    if (n <= 0 || n >= 100) {
        printf("Số đỉnh không hợp lệ.\n");
        return 1;
    }

    printf("Nhập ma trận kề (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }

    printf("Số cạnh trong đồ thị vô hướng là: %d\n", count);

    return 0;
}