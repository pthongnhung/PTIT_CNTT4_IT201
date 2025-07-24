#include <stdio.h>

int main() {
    int n, v;
    int matrix[100][100] = {0};

    printf("Nhập số đỉnh (0 < n < 100): ");
    scanf("%d", &n);
    printf("Nhập số cạnh (0 < v < 100): ");
    scanf("%d", &v);

    if (n <= 0 || n >= 100 || v <= 0 || v >= 100) {
        printf("Giá trị không hợp lệ.\n");
        return 1;
    }

    printf("Nhập %d cạnh (theo dạng: đỉnh1 đỉnh2):\n", v);
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < n && w >= 0 && w < n) {
            matrix[u][w] = 1;
            matrix[w][u] = 1;
        } else {
            printf("Cạnh (%d, %d) không hợp lệ. Bỏ qua.\n", u, w);
        }
    }

    int k, count = 0;
    printf("Nhập đỉnh cần kiểm tra: ");
    scanf("%d", &k);

    if (k < 0 || k >= n) {
        printf("Đỉnh không hợp lệ.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (matrix[k][i] == 1) {
            count++;
        }
    }

    printf("Số đỉnh liền kề với đỉnh %d là: %d\n", k, count);

    return 0;
}