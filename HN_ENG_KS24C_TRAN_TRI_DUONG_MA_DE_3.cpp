#include<stdio.h>
#include<math.h>
int prime_num(int n){
	if(n<2){
		return 0;
	}
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}
void swap(int &n,int &m){
	int temp=n;
	n=m;
	m=temp;
}
int main(){
	int n=0;
	do{ 
		printf("\n1.Nhap so phan tu va gia tri cho mang\n");
		printf("2.In ra cac phan tu trong mang\n");
		printf("3.Dem so luong cac so nguyen to trong mang\n");
		printf("4.Tim gia tri nho thu hai trong mang\n");
		printf("5.Them phan tu vao mang\n");
		printf("6.Xoa 1 phan tu\n");
		printf("7.Sap xep mang theo thu tu giam dan\n");
		printf("8.Tim kiem 1 phan tu trong mang\n");
		printf("9.Xoa phan tu trung lap va hien thi phan tu doc nhat trong mang\n");
		printf("10.Dao nguoc cac phan tu trong mang\n");
		printf("11.Thoat\n");	
		int a[100];
		int choice;
		printf("Nhap vao lua chon cua ban :");
		scanf("%d",&choice);
		if(choice==1){
			printf("Nhap so phan tu va gia tri cho mang\n");
			printf("Nhap vao so phan tu :");
			scanf("%d",&n);
			if(n<1){
				printf("So phan tu khong hop le!\n");
				continue;
			}
			for(int i=0;i<n;i++){
				printf("Nhap vao phan tu thu %d :",i+1);
				scanf("%d",&a[i]);
			}
		}
		else if (choice==2){
			printf("In ra cac phan tu trong mang\n");
			if(n<1){
				printf("Khong the in mang do so phan tu khong hop le !\n");
				continue;
			}
			printf("In mang:");
			for(int i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
		}
		else if(choice==3){
			printf("Dem so luong cac so nguyen to trong mang\n");
			int index=0;
			for(int i=0;i<n;i++){
				if(prime_num(a[i])==1){
					index+=1;
				}
			}
			printf("So luong so nguyen to trong mang la :%d",index);
			printf("\n");
		}
		else if(choice==4){
			printf("Tim gia tri nho thu hai trong mang\n");
			if(n<2){
				printf("Khong co so nho thu 2!\n");
				continue;
			}
			int min_1st=a[0];
			int min_2nd=a[1];
			for(int i=0;i<n;i++){
				if(min_1st>a[i]){
					min_1st=a[i];
				}
			}
			for(int i=0;i<n;i++){
				if(min_2nd>a[i]&&a[i]!=min_1st){
				min_2nd=a[i];
				}
			}
			printf("So nho thu 2 trong mang la :%d",min_2nd);
			printf("\n");
		}
		else if(choice==5){
			printf("Them phan tu vao mang\n");
			int pos;
			int value;
			printf("Nhap vao vi tri cua ban (0-%d):",n+1);
			scanf("%d",&pos);
			if(pos==0){
				pos=1;
			}
			if(pos<1||pos>n+1){
				printf("Vi tri khong hop le !\n");
				continue;
			}
			printf("Nhap vao gia tri cua ban :");
			scanf("%d",&value);
			for(int i=n;i>=pos;i--){
				a[i]=a[i-1];
			}
			a[pos-1]=value;
			n+=1;
			printf("Them phan tu thanh cong!\n");
		}
		else if(choice==6){
			printf("Xoa 1 phan tu\n");
			int pos;
			printf("Nhap vao vi tri muon xoa (1-%d):",n);
			scanf("%d",&pos);
			if(pos<1||pos>n){
				printf("Vi tri khong hop le !\n");
				continue;
			}
			for(int i=pos-1;i<n;i++){
				a[i]=a[i+1];
			}
			n-=1;
			printf("Xoa phan tu thanh cong!\n");
		}
		else if(choice==7){
			printf("Sap xep mang theo thu tu giam dan\n");
			if(n<2){
				printf("Khong the sap xep vi phan tu qua it !\n");
				continue;
			}
			for(int i=1;i<n;i++){
				int temp=a[i];
				int j=i-1;
				while(j>=0&&temp>a[j]){
					a[j+1]=a[j];
					j-=1;
				}
				a[j+1]=temp;
			}
			printf("Sap xep mang giam dan thanh cong!\n");
		}
		else if(choice==8){
			printf("Tim kiem 1 phan tu trong mang\n");
			for(int i=1;i<n;i++){
				int temp=a[i];
				int j=i-1;
				while(j>=0&&temp<a[j]){
					a[j+1]=a[j];
					j-=1;
				}
				a[j+1]=temp;
			}
			printf("Sap xep mang tang dan thanh cong !\n");
			int number;
			int pos=-1;
			int r=n-1;
			int l=0;
			printf("Nhap vao phan tu muon tim kiem :");
			scanf("%d",&number);
			while(l<=r){
				int m=(l+r)/2;
				if(a[m]==number){
					pos=m;
					break;
				}
				else if(a[m]>number){
					r=m-1;
				}
				else{
					l=m+1;
				}
			}
			if(pos==-1){
				printf("Khong tim thay phan tu vua nhap\n");
			}
			else{
				printf("Vi tri cua %d trong mang la :%d\n",number,pos);
			}
		}
		else if(choice==9){
			int k=0;
			int b[100]={0};
			int c[100];
			for(int i=0;i<n;i++){
				if(b[a[i]]==0){
					c[k]=a[i];
					b[a[i]]=1;
					k+=1;
				}
			}
			printf("Xoa cac phan tu trung thanh cong\n");
			n=k;
			for(int i=0;i<n;i++){
				a[i]=c[i];
			}	
		}
		else if(choice==10){
			int m=n/2;
			for(int i=0;i<m;i++){
				swap(a[i],a[n-i-1]);
			}
			printf("Dao nguoc thanh cong !\n");
		}
		else if(choice==11){
			printf("Thoat\n");
			return 0;
		}
		else{
			printf("Lua chon khong hop le !\n");
		}			
	}while(true);
}