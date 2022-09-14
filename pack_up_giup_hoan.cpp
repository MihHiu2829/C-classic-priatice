#include<bits/stdc++.h>
using namespace std ; 
typedef struct KyTU
{
	char ten[10] ;  
	int stt ;   
 } ;  
void xulichuoi(char a[500])
{
//	char tmp[500] = a[] ,  // 

char tmp[500]  ; 
		KyTU b[10] ;  
	strcpy(tmp,a) ;  
	int n =strlen(a), count = 0 , indexWords = 0  ;
	for(int i=0;i< n;i++)
	{
		if(tmp[i] == ' ') 
		{
			char a01[10] ="";  
			for(int y= indexWords;y < i;y++)
			{
				if(a[i] < 49 and a[i] > 57)
				{
					 strcat(a01,(tmp[i]+"")) ; 
				 }else (b[count].stt = tmp[i] - 49 ) ;   
			}
			indexWords = i+1 ;  
				strcpy(b[count].ten,a01) ;
				count++ ;  
		}
	}
	for(int i=0;i<3;i++)
	{
		cout<<b[i].ten<<" " ; 
	}
}
int main()
{
	char a[500]  ; 
	cout<<"Nhap ki tu muon chuyen doi" ; 
	fflush(stdin) ; 
	gets(a) ;  
	xulichuoi(a) ; 
}
