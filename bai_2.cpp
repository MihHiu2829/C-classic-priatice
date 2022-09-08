#include <bits/stdc++.h>
using namespace std ; 
typedef struct Sach
{
	int maSach ; 
	char tenSacg[40] ; 
	float giaSach ; 
}book ;  
void input(book &a)
{
		fflush(stdin) ; 
	cout<<"Nhap ten sach: " ; 
	gets(a.tenSacg) ;
		fflush(stdin) ; 
	cout<<"Nhap ma sach" ; 
	cin>>a.maSach ; 
	cout<<"Nhap gia cua "<<a.tenSacg ; 
	cin>>a.giaSach ; 
}
void  inputs(book a[],int &n)
{
	cout<<"Nhap so cuon sach: " ; 
	cin>>n; 
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap quyen sach thu %d"<<i+1<<endl ;
		input(a[i]);
	}
}
void output(book a)
{
	printf("%-12d %-45s %-20f\n",a.maSach,a.tenSacg,a.giaSach); 
}
void outputs(book a[],int n)
{
	cout<<"Cuon sach co trong chuong trinh"<<endl ;  
	 printf("%-12s %-45s %-20s\n", "Ma id", "Ten sach", "don gia");
	for(int i=0;i<n;i++)
	{
		output(a[i]) ;  
	}
}

bool timTuyenTinh(book a[],int n, int x)
{
	for(int i=0;i<n;i++)
	{
		if(a[i].maSach == x)
		  return 1 ; 
	}
	return 0 ;  
}
void sapxep(book a[],int n)
{
	book tmp ;  
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].maSach > a[j].maSach)
			{
				tmp = a[i] ;  
				a[i] = a[j] ;  
				a[j] = tmp ;
			}
//			tmp = a[i] ;  
//			a[i] = a[j] ;  
//			a[j] = tmp ;  
		}
	}
}
bool timNhiPhan(book a[],int n,int X)
{
//	if(n == 0 ) return 0 ; 
//	if(a[n-1].maSach == X) return 1 ; 
//	return timNhiPhan(a,n-1,X) ;  

		int left = 0 , right = n - 1 ;  
		while(left <= right)
		{
			int mid = (left+right)/2 ;  
			if(a[mid].maSach == X ) return 1 ;  
			if(a[mid].maSach < X ) left = mid + 1 ;  
			else right = mid - 1 ;  
		}
		return -1 ; 
}
void xuatSachTheoY(char y[],int n, book a[])
{
      for(int i=0;i<n;i++)
      {
      	if(strcmp(a[i].tenSacg,y)==0)
      	{
      		cout<<endl;  
      	 output(a[i]);
		  }
	  }
}
void xuatMax(book a[],int n)
{
	float max = a[n-1].giaSach ;  
	 printf("%-12s %-45s %-20s\n", "Ma id", "Ten sach", "don gia");
	for(int i=n-1;i>0;i--)
	{
		if(max == a[i].giaSach)
				output(a[i]) ;  
	}
}
int main()
{
	book a[100] ;  
	int n ;
	inputs(a,n) ; 
	outputs(a,n) ; 
	int X ; 
	cout<<"Nhap ma cuon sach can tim: " ; 
	cin>>X ;   
		if(timTuyenTinh(a,n,X))cout<<"\nThay quyen sach can tim 1"<<endl; 
		else cout<<"Khong tim thay trong tim tuyen tinh\n" ; 
	sapxep(a,n);
	if(timNhiPhan(a,n,X)) cout<<"\nThay quyen sach can tim 2"<<endl ;
	else cout<<"Khong tim thay trong tim nhi phan\n" ; 

	char y[40] ;  
	cout<<"Nhap ten cuon sach can tim: " ; 
	fflush(stdin) ; 
	gets(y) ; 
	xuatSachTheoY(y,n,a) ;
	cout<<"Cac cuon sach co gia cao nhat: " ; 
	xuatMax(a,n) ;
	
}

