#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 100, arr[a], n, choice, count = 0, max, check = 0, index, position[a], j, numbers, sum, flag = 1;
    do
    {
        if (n != 0)
            check = 1;
        else
            check = 0;
        printf("\n1. Nhap do dai cua mang va cac gia tri cua mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. In ra so luong cac so hoan hao trong mang\n");
        printf("4. In ra phan tu nho thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri dau tien trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang giam dan\n");
        printf("8. Tim kiem phan tu\n");
        printf("9. Sap xep mang va hien thi toan bo phan tu co trong mang sao cho toan bo so le dung truoc, so chan dung sau\n");
        printf("10. Dao nguoc thu tu cua cac phan tu co trong mang va hien thi ra toan bo phan tu co trong mang\n");
        printf("11. Thoat\n");
        printf("Hay chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nNhap do dai cua mang: ");
            scanf("%d", &n);
            a = n;
            for (int i = 0; i < n; i++)
            {
                check = 1;
                printf("Nhap phan tu arr[%d]: ", i);
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                printf("\nCac phan tu trong mang la: ");
                for (int i = 0; i < n; i++)
                {
                    printf("arr[%d] = %d  ", i, arr[i]);
                }
                printf("\n");
            }
            break;
        case 3:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                count = 0;
                for (int i = 0; i < n; i++)
                {
                    sum = 0;
                    for (int j = 1; j < arr[i]; j++)
                    {
                        if (arr[i] % j == 0)
                        {
                            sum += j;
                        }
                    }
                    if (sum == arr[i]){
                        count++;
                    }
                }
                printf("\nSo luong cac so hoan hao trong mang: %d\n", count);
            }
            break;
        case 4:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                printf("\nSo nho thu hai trong mang la: ");
                int min1 = 1000000000, min2 = 1000000000;
                for (int i = 0; i < n; i++)
                {
                    if (min1 > arr[i]){
                        min1 = arr[i];
                    }
                }
                for (int i = 0; i < n; i++)
                {
                    if (min2 > arr[i] && arr[i] != min1){
                        min2 = arr[i];
                    }
                }
                printf("%d", min2);
                printf("\n");
            }
            break;
        case 5:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang");
            }
            else
            {
                for (int i = n; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                n++;
                printf("\nNhap gia tri phan tu can them: ");
                scanf("%d", &arr[index]);
            }
            break;
        case 6:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                printf("\nNhap vi tri can xoa phan tu: ");
                scanf("%d", &index);
                if (index >= n)
                {
                    printf("\nVi tri ban nhap vuot qua do dai mang\n");
                }
                else
                {
                    for (int i = index; i < n; i++)
                    {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                }
            }
            break;
        case 7:
            if (check == 0){
                printf("\nBan chua them phan tu vao mang\n");
            }
            else {
                for (int i = 0; i < n; i++){
                    for (int j = i + 1; j < n; j++){
                        if (arr[i] < arr[j]){
                            int x = arr[i];
                            arr[i] = arr[j];
                            arr[j] = x;
                        }
                    }
                }
            }
            break;
        case 8:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                printf("\nNhap phan tu can tim kiem :");
                scanf("%d", &numbers);
                count = 0;
                for (int i = 0; i < n; i++){
                    for (int j = i + 1; j < n; j++){
                        if (arr[i] > arr[j]){
                            int x = arr[i];
                            arr[i] = arr[j];
                            arr[j] = x;
                        }
                    }
                }
                int left = 0, right = n - 1, pos;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == numbers)
                        pos = mid;
                    if (arr[mid] < numbers)
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                printf("Vi tri cua phan tu can tim kiem la : %d", pos);
                printf("\n");
            }
            break;
        
        case 9:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {

                for (int i = 0; i < n; i++){
                    for (int j = i + 1; j < n; j++){
                        if (arr[i] > arr[j]){
                            int x = arr[i];
                            arr[i] = arr[j];
                            arr[j] = x;
                        }
                    }
                }
                int b[n];
                int count1 = 0;
                for (int i = 0; i < n; i++){
                    if (arr[i] % 2 == 1) {
                        b[count++] = arr[i];
                    }
                }
                for (int i = 0; i < n; i++){
                    if (arr[i] % 2 == 0) {
                        b[count++] = arr[i];
                    }
                }
                for (int i = 0; i < n; i++){
                    arr[i] = b[i];
                    printf("%d ", arr[i]);
                }
            }
            break;
        case 10:
            if (check == 0)
            {
                printf("\nBan chua them phan tu vao mang\n");
            }
            else
            {
                printf("\nCac phan tu trong mang la: ");
                for (int i = 0; i < n / 2; i++){
                    int x = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = x;
                }
                for (int i = 0; i < n; i++){
                    printf("%d ", arr[i]);
                }
            }
            break;
        case 11:
            flag = 0;
            break;
        }
        if (flag == 0)
            break;
    } while (1);
    return 0;
}
