#include <stdio.h>

int main() {
    int arr[99999], n = 0, menu, value, index;
    while (1) {
        printf("\n\t\tMENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong chan le trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao dau mang\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang giam dan\n");
        printf("8. Tim kiem phan tu trong mang\n");
        printf("9. In so nguyen to trong mang va binh phuong\n");
        printf("10. Sap xep mang giam dan \n");
        printf("11. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &menu);
        switch (menu) {
            case 1: {
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                printf("Nhap cac phan tu cua mang:\n");
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = ", i);
                    scanf("%d", &arr[i]);
                }
                break;
            }
            case 2: {
                for (int i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
            }
            case 3: {
                int chan = 0, le = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] % 2 == 0) {
                        chan++;
                    } else {
                        le++;
                    }
                }
                printf("So phan tu chan: %d\n", chan);
                printf("So phan tu le: %d\n", le);
                break;
            }
            case 4: {
                int max1 = arr[0], max2 = 0;
                for (int i = 1; i < n; i++) {
                    if (arr[i] > max1) {
                        max2 = max1;
                        max1 = arr[i];
                    } else if (arr[i] > max2 && arr[i] < max1) {
                        max2 = arr[i];
                    }
                }
                printf("Gia tri lon thu hai: %d\n", max2);
                break;
            }
            case 5: { 
                printf("Nhap gia tri muon them vao dau: ");
                scanf("%d", &value);
                for (int i = n; i > 0; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[0] = value;
                n++;
                break;
            }
            case 6: {
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &index);
                if (index >= 0 && index < n) {
                    for (int i = index; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                } else {
                    printf("Vi tri khong hop le!\n");
                }
                break;
            }
            case 7: {
                for (int i = 1; i < n; i++) {
                    int temp = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < temp) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = temp;
                }
                printf("Mang sau khi sap xep giam dan (Insertion Sort):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 8: {
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);
                int left = 0, right = n - 1, found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == value) {
                        printf("Phan tu %d co trong mang tai vi tri %d.\n", value, mid);
                        found = 1;
                        break;
                    } else if (arr[mid] < value) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (!found) {
                    printf("Phan tu %d khong co trong mang.\n", value);
                }
                break;
            }
            case 9: {
                int found = 0;
                for (int i = 0; i < n; i++) {
                    int count = 1;
                    if (arr[i] < 2) {
                        count = 0;
                    } else {
                        for (int j = 2; j * j <= arr[i]; j++) {
                            if (arr[i] % j == 0) {
                                count = 0;
                                break;
                            }
                        }
                    }
                    if (count) {
                        printf("%d^2 = %d\n", arr[i], arr[i] * arr[i]);
                        found = 1;
                    }
                }  
            
                if (!found) {
                    printf("Khong co so nguyen to nao trong mang.\n");
                }
                break;
            }
            case 10: {
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] < arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep giam dan (Bubble Sort):\n");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            }
            case 11: {
                printf("Thoat chuong trinh.\n");
                return;
            }
            default:
                printf("Lua chon khong hop le!. Vui long chon lai :))\n");
        }
    }
    return 0;
}

