/*================================

            Vo Tan Dung
          MSSV: 2011068809

    - Danh sach lien ket don 
    - Infor = cong nhan
    - Yeu cau: Quan ly cong nhan

==================================*/

#include <bits/stdc++.h>
using namespace std;
struct Date
{
	string Day;
	string Month;
	string Year;
};
struct workers
{
	int id;
    string name;
	Date date;
	int  salary;
};
struct Node
{
	workers info;
	Node* pNext;
};
struct linkedList
{
    Node* pHead;
    Node* pTail;
};
void PrintDate(Date date)
{
	cout << setw(2) << left << date.Day << '/' << setw(2) << left << date.Month << '/' << setw(8) << left << date.Year << "| ";
}
void inputDate(Date &date)
{
    cout << endl << "  + Ngay: "; cin >> date.Day;
    cout << "  + Thang: "; cin >> date.Month;
    cout << "  + Nam: "; cin >> date.Year;
    
}
void init(linkedList &list)
{
    list.pHead= NULL ;
    list.pTail=NULL;
}
int isEmpty(linkedList list)
{
    if (list.pHead==NULL)
        return true;
    else return false;
}
//==============================================
Node* createNode(workers x)
{
	Node* p = new Node;
	p->info = x;
	p->pNext = NULL;
	return p;
}
//==============================================
void input(workers &x)
{
    cout << " - ID: "; cin >> x.id;
    cout << " - Ho va ten:"; 
    cin.ignore();
    getline(cin,x.name);
    cout << " - Ngay thang nam sinh: "; inputDate(x.date);
    cout << " - Muc luong: "; cin >> x.salary;
}
//==============================================
void numberOfWorker(int &n)
{
	do
	{
		cout << "Nhap so luong cong nhan: ";
		cin >> n;
		if(n<1)	cout << "Ban nhap sai, xin nhap lai(N>0).\n";
	}while(n<1);
}
//==============================================
void insertFirst(linkedList &list, workers x)
{
	Node* p = createNode(x);
	p->pNext = list.pHead;
	list.pHead = p;
}
void insertLast(linkedList &list, workers x)
{
	Node* q = createNode(x);
	if(isEmpty(list))
		insertFirst(list,x);
	else
	{
		Node* p = list.pHead;
		while(p->pNext !=NULL)
		{
			p = p->pNext;
		}
		p->pNext = q;
        list.pTail=q;
	}
}
//==============================================
void enterList(linkedList &list)
{
	int n;
	workers x;
	numberOfWorker(n);
	for(int i=0;i<n;i++)
	{
		cout << " # Nhap thong tin cong nhan thu " << i+1 << ": " << endl;
		input(x);
        insertLast(list,x);
	}
}
//==============================================
void table()
{
	cout << "--------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "|      ID" << "|";
    cout << setw(25) << left << "        Ho va ten" << "|";
    cout << setw(15) << left << "   Ngay sinh" << "|";
    cout << setw(15) << left << "   Muc luong" << "|" << endl ;
	cout << "--------------------------------------------------------------------------";
}
void print(Node* pHead)
{
	table();
    cout << endl;
    cout << "|" << setw(14) << right << pHead->info.id << "| ";
    cout << setw(24) << left <<  pHead->info.name << "| ";
    PrintDate(pHead->info.date);
    cout << setw(14) << left << pHead->info.salary << "|" << endl;	
    cout << "--------------------------------------------------------------------------";
	cout << endl;
	
}
void printList(linkedList list)
{
    if (isEmpty(list))
	{
		cout << " - Danh sach rong\n";
	}
    else 
    for(Node* i=list.pHead ; i!=NULL ; i= i->pNext)
	{
		cout << "|" << setw(14) << right << i->info.id << "| ";
		cout << setw(24) << left << i->info.name << "| ";
		PrintDate(i->info.date);
		cout << setw(14) <<	 left << i->info.salary << "|" << endl;	
	}
}
Node* highestSalary(linkedList &list)
{
	Node* max=list.pHead;
    for (Node* i=list.pHead->pNext ; i!=NULL ; i= i->pNext)
		if (max->info.salary<i->info.salary) max=i;
	return max;
}
//==============================================
int count(linkedList &list)
{		
	int dem=0;
	for (Node* i=list.pHead ; i!=NULL ; i= i->pNext)
		dem++;
	return dem;
}
Node* search(linkedList &list,int x)
{
	for (Node* i=list.pHead ; i!=NULL ; i= i->pNext)
		if (i->info.id==x) return i;
	return NULL;
}
void deleteAt(linkedList &list,int x)
{
	if (list.pHead->info.id==x) 
	{
		Node* temp;
		temp->pNext = list.pHead->pNext;
	    list.pHead->pNext = list.pHead->pNext->pNext;
	    delete(temp);
	} else
	for (Node* i=list.pHead->pNext;i!=NULL;i=i->pNext)
    {
        if (i->info.id==x)
        {
            Node* temp;
			temp->pNext = i->pNext;
	        i->pNext = i->pNext->pNext;
	        delete(temp);
        }
    }
}
void deleteFirst(linkedList &list)
{
    if (isEmpty(list))
	{
		cout << "\nDanh sach rong\n";
	}
    else 
    {
        Node* p=list.pHead;
        list.pHead=list.pHead->pNext;
        delete(p);
    }
}
void deleteLast(linkedList &list)
{
    if (isEmpty(list))
	{
		cout << "\nDanh sach rong\n";
	}
    else 
    {     
        Node *p  ; 
    	 for(Node *i=list.pHead;i;i=i->pNext){
    	 	    if(i == list.pTail){
    	 	            p->pNext =  NULL  ; 
						 list.pTail = p  ; 
						 delete(i); 	
						 return ; 
				 }
				 p = i ;  
		 } ; 
		
   }
}
void Quicksort(linkedList &list)
{
    linkedList list1,list2;
    Node* tag;
    Node* temp;
    if (list.pHead==list.pTail) return;
    init(list1); init(list2);
    tag=list.pHead;
    list.pHead=list.pHead->pNext;
    tag->pNext=NULL;
    while (list.pHead!=NULL) 
    {
        temp=list.pHead;
        list.pHead=list.pHead->pNext;
        temp->pNext=NULL;
        if (temp->info.id<tag->info.id) insertFirst(list1,temp->info);
        else insertFirst(list2,temp->info);
    }
    Quicksort(list1);
    Quicksort(list2);
    if (list1.pHead!=NULL) 
    {
        list.pHead=list1.pHead;
        list1.pTail->pNext =tag;
    }
    else list.pHead=tag;
    tag->pNext=list2.pHead;
    if (list2.pHead!=NULL)
    {
        list.pTail=list2.pTail;
    } else list.pTail=tag;
}
//==============================================
/*Node* LonNhat(Node* pHead)
{
	Node* max=pHead;
	if (isEmpty(pHead))
	{
		cout << endl << "Danh sach rong" << endl;
	}
	else 
	{
			if (max->info<i->info) max=i;
	}
}
//==============================================
void DeleteAt(Node* pHead,int x)
{
	for (Node* i=pHead;i!=NULL;i=i->pNext)
    {
        if (i->info==x)
        {
            Node* temp;
			temp->pNext = i->pNext;
	        i->pNext = i->pNext->pNext;
	        delete(temp);
        }
    }
}
//==============================================
void BasicSort(Node* pHead)
{
    int temp;
    for (Node* i=pHead;i!=NULL;i=i->pNext)
        for (Node* j=i->pNext; j!=NULL;j=j->pNext)
            if (i->info>j->info)
            {
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
}

//==============================================
void NhanBanNhieuMax(Node* &pHead)
{   
	Node* ln=LonNhat(pHead);
    for (Node* i=pHead->pNext;i!=NULL;i=i->pNext)
    {
        if (i->info==ln->info)
        {
			insertAfter(ln,ln->info);
			i=i->pNext->pNext;
		}
    }
}
void Nhanban1Max(Node* &pHead)
{
    Node* ln=LonNhat(pHead);
    insertAfter(ln,ln->info);
}
void XoaDau(Node* &pHead)
{
    if (isEmpty(pHead)==1)
	{
		cout << "\nDs rong\n";
	}
    else 
    {
        Node* p=pHead;
        pHead=pHead->pNext;
        delete(p);
    }
}
void XoaCuoi(Node* &pHead)
{
    if (isEmpty(pHead)==1)
	{
		cout << " - Danh sach rong\n";
	}
    else 
    {
        Node* i;
        for (i = pHead->pNext;i->pNext->pNext!=NULL;i=i->pNext)
            ;
        i->pNext= NULL;
        Node* p=i->pNext;
        delete(p);
	}
}*/
void Menu()
{ 
	cout << endl<< "\t\t\t============================ MENU ============================" << endl;
	cout << setw(64) << left << "\t\t\t 1. Nhap danh sach cong nhan." << endl;
	cout << setw(64) << left << "\t\t\t 2. Xuat danh sach cong nhan." << endl;
	cout << setw(64) << left << "\t\t\t 3. Sap xep danh sach tang dan theo ID. "<< endl;
	cout << setw(64) << left << "\t\t\t 4. Xuat thong tin cong nhan thu K trong danh sach. "<< endl;
	cout << setw(64) << left << "\t\t\t 5. Thong tin cong nhan co muc luong cao nhat. " << endl;
	cout << setw(64) << left << "\t\t\t 6. Tong so cong nhan hien tai. " << endl;
	cout << setw(64) << left << "\t\t\t 7. Xoa cong nhan theo ID. " << endl;
	cout << setw(64) << left << "\t\t\t 8. Xoa cong nhan dau tien. " << endl;
	cout << setw(64) << left << "\t\t\t 9. Xoa cong nhan cuoi cung. " << endl;
	cout << setw(64) << left << "\t\t\t 0. Thoat chuong trinh. " << endl;
	cout << endl << "\t\t\tMoi ban chon chuc nang :   " ;
}

int main()
{
	linkedList list;
	init(list);
    cout << endl;
    int luaChon;
    do 
	{
		system("cls");
		Menu();
		cin >> luaChon;
		cout << endl;
		cout << endl << "\t\t\t==============================================================" << endl  << endl; 
		switch(luaChon) 
		{	
			case 1:
				enterList(list);
				break;

			case 2:
				cout << "Thong tin cac cong nhan trong danh sach: " << endl << endl;
				table();
				cout << endl;
				printList(list);
				cout << "--------------------------------------------------------------------------";
				cout << endl;
				system("pause");
				break;

			case 3:
				Quicksort(list);
				cout << endl << " - Da sap xep - " << endl;
				system("pause");
				break;

			case 4:
				int x;
				cout << "Nhap vao ID can tim: "; cin >> x;
				print(search(list,x));
				system("pause");
				break;

            case 5:
                cout << "Thong tin cong nhan co muc luong cao nhat: " << endl;
                print(highestSalary(list));
				cout << endl;
                system("pause");
                break;

			case 6:
				cout << "Tong so cong nhan hien tai: " << count(list) << " cong nhan."<< endl;
				cout << endl;
				system("pause");
				break;

			case 7:
				int xx;
				cout << "Nhap vao ID cong nhan can xoa: "; cin >> xx;
				deleteAt(list,xx);
				cout << " - Da xoa - " << endl;
				system("pause");
				break;

			case 8:
				deleteFirst(list);
				cout << " - Da xoa - " << endl;
				system("pause");
				break;

			case 9:
				deleteLast(list);
				cout << " - Da xoa - " << endl;
				system("pause");
				break;

			default:
				cout << "\nSai chuc nang, vui long chon lai!\n";
				break;
				
			case 0:
				cout << "\nBan da chon thoat chuong trinh!\n";
                return 0;
            	break;
		}		
		cout << endl  << endl << "====================================" << endl; 
		cout << "\nMoi ban chon chuc nang: " << endl;
	} while(luaChon);
	return 0;
}
