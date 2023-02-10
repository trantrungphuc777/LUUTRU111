#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
struct SinhVien
{
	   char   Masv[10];
	   char   Hotensv[50];
	   char   Phai[5];
	   int    Namsinh;
	   char   Quequan[100];
	   char   Nganhhoc[50];
	   float  Kqcuoikhoa;
	   char   Xeploai[20];
};
typedef struct SinhVien SINHVIEN;

void TIMSV   (SINHVIEN a[], int n);
void INGX    (SINHVIEN a[], int n);
void Sapxep  (SINHVIEN a[], int n);
void Nhapsv  (SINHVIEN &x);
void NhapsvN (SINHVIEN a[], int n);
void Xuatsv  (SINHVIEN x);
void XuatsvN (SINHVIEN a[], int n);


int main()
{
	int n, key;
	SINHVIEN x, a[100];
	while(true)
	{
		 system("cls");
		 printf("*************************************************\n");
		 printf("**           CHUONG TRINH QUAN LY SV           **\n");
	     printf("**           1.Nhap DS Sinh Vien               **\n");
		 printf("**           2.IN DS Sinh Vien                 **\n");
		 printf("**           3.Sap xep theo KQCK               **\n");
		 printf("**           4.In SV Gioi, Xuat sac            **\n");
		 printf("**           5.Tim kiem SV theo MSSV           **\n");
		 printf("**           0.Thoat                           **\n");
         printf("*************************************************\n");
	printf("\n       \t\t AN PHIM DE CHON :     ");
	scanf("%d",&key);
	switch(key)
	{
		  case 1:
		  	do
		  	{
			  printf("\n\n\nNhap so luong sinh vien :");
	          scanf("%d",&n);
			}while(n<=0);
		    NhapsvN(a,n);
		    printf("\nBam phim bat ky de tiep tuc !");
		    getch();
		    break;
		  case 2:
		  	XuatsvN(a,n);
		  	printf("\nBam phim bat ky de tiep tuc !");
		    getch();
		    break;
		  case 3:
		  	printf("\nBam phim bat ky de tiep tuc !");
		  	Sapxep(a,n);
		  	XuatsvN(a,n);
		  	getch();
		    break;
		  case 4:
		  	printf("\nBam phim bat ky de tiep tuc !");
		  	INGX(a,n);
		    XuatsvN(a,n);
		    getch();
            break;
		  case 5:
		  	printf("\nBam phim bat ky de tiep tuc !");
		  	TIMSV(a,n);
		  	getch();
		    break;
		  case 0:
		  	exit(1);
		  default:
		  	printf("\nKhong co chuc nang nay !");
		  	printf("\nBam phim bat ky de tiep tuc !");
		  	getch();
		  	break;
		  	
	}
	}
}







void Nhapsv(SINHVIEN &x)
{
	 fflush(stdin);
	 printf("\nNhap Ma So SV :");
	 gets(x.Masv);
     fflush(stdin);
     printf("\nNhap ho ten :");
     gets(x.Hotensv);
     fflush(stdin);
     printf("\nNhap phai :");
     gets(x.Phai);
     fflush(stdin);
     printf("\nNhap que quan :");
     gets(x.Quequan);
     fflush(stdin);
     printf("\nNhap nganh dang theo hoc :");
     gets(x.Nganhhoc);
     
     do
     {
        printf("\nNhap nam sinh :");
        scanf("%d",&x.Namsinh);
     }  while(x.Namsinh<1980 || x.Namsinh >2010);
	 
	 do
	 {
	 	printf("\nNhap ket qua cuoi khoa :");
	 	scanf("%f",&x.Kqcuoikhoa);
	 }  while(x.Kqcuoikhoa <0.0 || x.Kqcuoikhoa > 4.0);
	 
	 fflush(stdin);
	 if(x.Kqcuoikhoa<=1.5)
	 {
	   strcpy(x.Xeploai,"Yeu"); 
	 }
	 else  
	   if(x.Kqcuoikhoa<=2.5)
	   {
	   	 strcpy(x.Xeploai,"Trung binh");
	   }
	   else
	     if(x.Kqcuoikhoa<=3.0)
	     {
	       strcpy(x.Xeploai,"Kha");
	     }
	     else
	        if(x.Kqcuoikhoa<=3.8)
	        {
	          strcpy(x.Xeploai,"Gioi");
	        }
	        else
	        {
	          strcpy(x.Xeploai,"Xuat sac");
	        } 
}


void NhapsvN(SINHVIEN a[], int n)
{
	 for(int i=0;i<n;i++)
	 {
	 	printf("\nNhap sinh vien thu %d",i+1);
	 	Nhapsv(a[i]);
	 }
}


void Xuatsv(SINHVIEN x)
{
	 printf("|%5s  |%-18s|%-6s|%10d|%-11s|%12.1f   |%-10s|%-10s|",x.Masv,x.Hotensv,x.Phai,x.Namsinh,x.Nganhhoc,x.Kqcuoikhoa,x.Xeploai,x.Quequan);
}

void XuatsvN(SINHVIEN a[], int n)
{
	system("cls");
	printf("\n\n|----------------------------------------------------------------------------------------------|\n");
    printf("| Ma SV | Ho ten sinh vien | Phai | Nam Sinh | Nganh hoc | KQ cuoi khoa  | Xep loai | Que quan |");
	for(int i=0;i<n;i++)
	{
		printf("\n|-------|------------------|------|----------|-----------|---------------|----------|----------|\n");
		Xuatsv(a[i]);
	}	
}

void Sapxep(SINHVIEN a[], int n)
{
	SINHVIEN tmp;
	for(int i=0;i<n;++i)
	{
	   for(int j=i+1;j<n;++j)
	   {
	   	  if(a[i].Kqcuoikhoa>a[j].Kqcuoikhoa)
	   	  {
	   	  	tmp   =a[i];
	   	  	a[i]  =a[j];
	   	  	a[j]  =tmp;
		  }
	   }
	}
}


void INGX(SINHVIEN a[], int n)
{
	system("cls");
	printf("\n\n|----------------------------------------------------------------------------------------------|\n");
	for(int i=0;i<n;i++)
    {
       if(a[i].Kqcuoikhoa>=3.0)
       {
	     printf("\n|-------|------------------|------|----------|-----------|---------------|----------|----------|\n"); 
         Xuatsv(a[i]);  
       }
    }
}


void TIMSV(SINHVIEN a[], int n)
{
	 system("cls");
	 fflush(stdin);
	 char Matim[10];
	 printf("\n\nNhap ma so sv can tim :");
	 gets(Matim);
	 printf("\n\n|----------------------------------------------------------------------------------------------|\n");
     printf("| Ma SV | Ho ten sinh vien | Phai | Nam Sinh | Nganh hoc | KQ cuoi khoa  | Xep loai | Que quan |");
	 for(int i=0;i<n;i++)
	 if(strcmp(a[i].Masv,Matim)==0)
	 {
	 	 printf("\n|-------|------------------|------|----------|-----------|---------------|----------|----------|\n");
         Xuatsv(a[i]);  
	 }
}
