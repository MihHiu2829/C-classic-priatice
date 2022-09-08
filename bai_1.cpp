 	#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
const int MAX = 100 ; 
void NhapSL(int &n)
{
	do{
		cout<<"Nhap so phan tu 0<sl<%d: ",MAX ; 
		cin>>n; 
	}while(n <=0 || n > MAX ) ; 
}
 
 void NhapMang(int a[],int n)
 {
   srand((unsigned int )time(NULL)) ;  	
   for(int i=0;i < n;i++)
			a[i] =15 + rand()%51 ; 
 }
 void XuatMang(int a[],int n)
 {
 	cout<<endl<<"Mang gom cac phan tu: "<<endl ;  
 	for(int i=0;i<n ; i++)
 	    cout<<a[i]<<" " ;  
 }
 int TinhTong(int a[],int n)
 {
 	int sum = 0 ;  
 	for(int i=0;i<n;i++)
 	{
 		sum+=a[i] ;  
	 }
	 return sum ; 
 }
 
 float TinhTrungBinhCong(int a[],int n)
 {
 	int sum = TinhTong(a,n) ; 
 	return ((float)sum/n );  
}
 int TimTuyenTinh(int a[],int n,int X)
 {
 	for(int i=0;i<n;i++)
 	{
 		if(a[i] == X)
 		 return i ; 
	 }
	 return -1 ; 
 }
 void SapXep(int a[],int n)
 {
 	int tmp = 0 ; 
 	for(int i=0;i<n-1;i++)
 	{
 		for(int j=i+1;j<n;j++)
 		{
 			if(a[i] > a[j])
 			{	 
 				tmp = a[i] ; 
				 a[i] = a[j] ; 
				 a[j] = tmp ;  
			 }
		 }
	 }
 }
 int TimNhiPhan(int a[],int n,int X)
 {
 			int left = 0 , right = n-1 ; 
			 while(left <= right)
			 {
			 	int mid = (left+right)/2 ;
			 	if(a[mid] == X) return mid ; 
			 	else  if(a[mid] < X ) 
			 	     left = mid + 1  ; 
			 	     else  right = mid -1 ; 
			   }  
			   return -1 ;  
	 }
//int binarySearch(int arr[], int l, int r, int x) {
//  if (r >= l) {
//    int mid = l + (r - l) / 2; 
//
//    if (arr[mid] == x)
//      return mid;
//    if (arr[mid] > x)
//      return binarySearch(arr, l, mid - 1, x);  
// 
//    return binarySearch(arr, mid + 1, r, x);
//  }
//  return -1;
//}
// }
int main()
{
	int a[MAX],n ; 
	NhapSL(n) ;  
	NhapMang(a,n) ; 
	XuatMang(a,n) ; 
	int tong = TinhTong(a,n) ; 
	float tbc = TinhTrungBinhCong(a,n) ;
	cout<<"Tong cac phan tu ="<<tong<<endl ; 
	cout<<"Trung binh cong cac phan tu = "<<tbc<<endl ; 
	
	int X ; 
	cout<<"Nhap gia tri can tim: " ;
	cin>>X ; 
	int vt = TimTuyenTinh(a,n,X) ;
	if(vt == -1)
	   cout<<"Khong tim thay"<<endl ;  
	else cout<<"Tim thay "<<X<<" tai vi tri "<<vt<<endl ;  
	SapXep(a,n)  ;
	cout<<"Mang sau khi sap tang "<<endl ; 
	XuatMang(a,n) ; 
	cout<<"Nhap gia tri can tim: " ; 
	cin>>X ; 
	vt = TimNhiPhan(a,n,X) ; 
    cout<<"Vi tri can tim: "<<vt<<endl  ;  
}
