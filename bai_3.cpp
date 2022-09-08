#include<bits/stdc++.h>
using namespace std ; 
typedef struct student{
   char name[40] ; 
   int ID ;  
   float diem ; 
   typedef struct date{
   	int ngay, thang , nam ;  
   };
   date ngaysinh ;
   
};

void input(student &a)
{ 
   cout<<"Nhap ten sinh vien"<<endl ; 
   fflush(stdin) ;  
   gets(a.name) ; 
   cout<<"Nhap ma sinh vien" ; 
     fflush(stdin) ; 
   cin>>a.ID ; 
   cout<<"Nhap diem cua sinh vien" ; 
   cin>>a.diem ; 
     fflush(stdin) ; 
   cout<<"Nhap ngay thang nam sinh cua sinh vien:";
   scanf("%d/%d/%d",&a.ngaysinh.ngay, &a.ngaysinh.thang, &a.ngaysinh.nam) ;  
}
void inputs(student a[],int &n)
{
	cout<<"Nhap so luong cua sinh vien: " ; 
	cin>>n  ; 
	for(int i=0;i<n;i++)
	{
		 input(a[i]) ; 
	}
}
void output(student a){
    
	printf("%-45s %-30d %-20f %-2d/%-2d/%-2d\n",a.name,a.ID,a.diem,a.ngaysinh.ngay, a.ngaysinh.thang, a.ngaysinh.nam) ; 
}
void outputs(student a[],int n)
{printf("%-45s %-30s %-20s %-20s\n","Ho va ten","Ma sinh vien","Diem sinh vien","Ngay Sinh");
		for(int i=0;i<n;i++)
		{
				output(a[i]) ; 	
		}
}
void timTenTheoUser(student a[],int n)  // cauu d 
{
	fflush(stdin)  ; 
	char ten[40]  ;   
	cout<<"Nhap ten sinh vien can tim" ; 
	gets(ten) ; 
	printf("%-45s %-30s %-20s %-20s\n","Ho va ten","Ma sinh vien","Diem sinh vien","Ngay Sinh");
	for(int i=0;i<n;i++)
	{
		
		if(strcmp(a[i].name,ten)==0)
		{
			output(a[i]) ;  
		}
	}
}
void xuatdiemlonhon5(student a[],int n) // cau e 
{
		printf("%-45s %-30s %-20s %-20s\n","Ho va ten","Ma sinh vien","Diem sinh vien","Ngay Sinh");
	for(int i=0;i<n;i++)
	{
		if(a[i].diem >= 5)
		   output(a[i]) ; 
	}
}
int demSinhVienCoDiemTHiLonHon8(student a[],int n) // cau f 
{
	int count = 0 ; 
		for(int i=0;i<n;i++)
		if(a[i].diem > 8)
		   count++ ; 
	return count ; 
}
int diemcaoNhat(student a[], int n)  // cho biet sinh vien co diem thi cao nhat 
{
	float max =0 ;  
	for(int i=0;i<n;i++)
	{
		if(a[i].diem > max ) max = a[i].diem ; 
	}
	return max ;  
}
int countSinhVienCaoNhat(student a[],int n)
{
	int max = diemcaoNhat(a,n)  ; 
	int count = 0 ;  
	for(int i=0;i<n;i++)
	{
		if(a[i].diem == max ) count++ ;  
	}
	return count ;  
}
void sapxepTheoDiem(student a[],int n)
{
	student  tmp ;  
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].diem > a[j].diem)
			{
				tmp = a[i] ;  
				a[i] = a[j] ;  
				a[j] = tmp ;
			} 
		}
	}
}
void sapxepDanhSachSinhVienTang(student a[],int n)
{
	student  tmp ;  
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].ID > a[j].ID)
			{
				tmp = a[i] ;  
				a[i] = a[j] ;  
				a[j] = tmp ;
			} 
		}
	}
}
int main()
{
	student a[100]  ; 
	 int n ;  
	inputs(a,n) ; 
	outputs(a,n) ;
	xuatdiemlonhon5(a,n) ; 
}
