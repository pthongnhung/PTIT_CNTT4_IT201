#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sort_string(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Loại bỏ ký tự xuống dòng '\n'

    // Xóa khoảng trắng đầu cuối
    int len = strlen(str);
    int isValid = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace(str[i])) {
            isValid = 1;
            break;
        }
    }

    if (!isValid) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("Truoc khi sap xep: \"%s\"\n", str);
    sort_string(str);
    printf("Sau khi sap xep: \"%s\"\n", str);

    return 0;
}
