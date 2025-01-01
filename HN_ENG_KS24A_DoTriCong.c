#include <stdio.h>

int main() {
    int arr[100];
    int n = 0;
    int choice;
    do {
        printf("MENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Tim gia tri nho nhat va lon nhat trong mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Them mot phan tu vao cuoi mang\n");
        printf("6. Xoa mot phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang giam dan (Bubble sort)\n");
        printf("8. Tim kiem phan tu trong mang (Linear search)\n");
        printf("9. In cac so nguyen to trong mang\n");
        printf("10. Sap xep mang tang dan (Selection sort)\n");
        printf("11. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap gia tri cac phan tu:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                printf("Cac phan tu trong mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }
            case 3: {
                int min = arr[0], max = arr[0];
                for (int i = 1; i < n; i++) {
                    if (arr[i] < min) 
					min = arr[i];
                    if (arr[i] > max) 
					max = arr[i];
                }
                printf("Gia tri nho nhat: %d\n", min);
                printf("Gia tri lon nhat: %d\n", max);
                break;
            }
            case 4: {
                int t = 0;
                for (int i = 0; i < n; i++) {
                    t += arr[i];
                }
                printf("Tong cac phan tu trong mang: %d\n", t);
                break;
            }
            case 5: {
                if (n >= 100) {
                    printf("Khong the them phan tu moi.\n");
                } else {
                    int value;
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    arr[n++] = value;
                    printf("Da them %d vao mang.\n", value);
                }
                break;
            }
            case 6: {
                int index;
                printf("Nhap vi tri can xoa (0-%d): ", n - 1);
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = index; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Da xoa phan tu tai vi tri %d.\n", index);
                }
                break;
            }
            case 7: {
            	 for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang da duoc sap xep theo thu tu giam dan.\n");
                break;
            }
            case 8: {
                int value, a = 0;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d nam tai vi tri %d.\n", value, i);
                       a = 1;
                    }
                }
                if (!a) {
                    printf("Khong tim thay phan tu %d trong mang.\n", value);
                }
                break;
            }
            case 9: {
                int f = 0;
                printf("Cac so nguyen to trong mang: ");
                for (int i = 0; i < n; i++) {
                    if (arr[i] > 1) {
                        int Num  = 1;
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                Num = 0;
                                break;
                            }
                        }
                        if (Num) {
                            printf("%d ", arr[i]);
                            f = 1;
                        }
                    }
                }
                if (!f) {
                    printf("Khong co so nguyen to nao trong mang.");
                }
                printf("\n");
                break;
            }
            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    int Number = i;
                    for (int j = i + 1; j < n; j++) {
                        if (arr[j] < arr[Number]) {
                            Number = j;
                        }
                    }
                    int temp = arr[i];
                    arr[i] = arr[Number];
                    arr[Number] = temp;
                }
                printf("Mang da duoc sap xep theo thu tu tang dan.\n");
                break;
            }
            case 11:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 11);
    return 0;
}

