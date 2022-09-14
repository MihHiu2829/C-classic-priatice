#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int Max = 100;
int n;
typedef struct employee
{
    string date, name;
    int id, salary;
} ee;
typedef struct node
{
    ee data;
    node *next;
} NODE;
typedef struct list
{
    NODE *head;
    NODE *tail;
} LIST;
void delete_fflush()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}
void Enter_employee(ee &a)
{
    cout << "Enter id of employee: ";
    cin >> a.id;
    cout << "Enter Name: ";
    delete_fflush();
    getline(cin, a.name);
    cout << "Enter salary of employee: ";
    cin >> a.salary;
    cout << "Enter date: ";
    delete_fflush();
    getline(cin, a.date);
}
void Displa(ee a)
{
    printf("%-20s %-20s %-15d %-10d", (a.name).c_str(), (a.date).c_str(), a.id, a.salary);
    cout << endl;
}
void Init(LIST &l)
{
    l.head = l.tail = NULL;
}
NODE *getNode(ee a)
{
    NODE *p = new NODE;
    if (p == NULL)
        return NULL;
    p->data = a;
    p->next = NULL;
    return p;
}
void addhead(LIST &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
        return;
    }
    p->next = l.head;
    l.head = p;
}
void addTail(LIST &l, NODE *p)
{
    if (l.head == NULL)
    {
        l.head = l.tail = p;
        return;
    }
    l.tail->next = p;
    l.tail = p;
}
void Input(LIST &a)
{
    cout << "\nEnter quanity employee of company: ";
    cin >> n;
    Init(a);
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter information of employee " << i + 1 << "\n"; 
          ee z  ; 
        Enter_employee(z);
        NODE *p = getNode(z);
        addTail(a, p);
    }
}
void Output(LIST a)
{
    if (a.head == NULL)
    {
        cout << "\nList employee is empty! ";
        return;
    }
    printf("%-20s %-20s %-15s %-10s", "full Name", "Date ", "IDentifier ", "Salary \n");
    for (NODE *p = a.head; p; p = p->next)
    {
        Displa(p->data);
    }
}
void Sort(LIST &a)
{
    for (NODE *p = a.head; p != a.tail; p = p->next)
    {
        for (NODE *q = p->next; q; q = q->next)
        {
            if (p->data.salary < q->data.salary)
                swap(p->data, q->data);
        }
    }
}
void addEmployee(LIST &a, NODE *p)
{
    if (a.head == NULL)
    {
        a.head = a.tail = p;
        return;
    }
    a.tail->next = p;
    a.tail = p;
}
void freedom(LIST &a)
{
    NODE *p;
    while (a.head != NULL)
    {
        p = a.head;
        a.head = p->next;
        delete (p);
    }
}
void delete_node(LIST &a, int az)
{
    NODE *k;
    for (NODE *p = a.head; p; p = p->next)
    {
        if ((p->data.id) == az)
        {
            k->next = p->next;
            delete (p);
            cout << "\nComplete!";
            return;
        }
        k = p;
    }
    cout << "\nNo id to delete! ";
}
void fix_in4(LIST &l,string name0){ 
       NODE *k ; 
       ee tmp ;   
    for(NODE *p=l.head;p;p=p->next){
          if(p->data.name == name0){
                     Enter_employee(tmp); 
                     NODE *xx = getNode(tmp); 
                     k->next = xx ; 
                     xx->next=p->next ; 
                     delete(p);
                     return ;           
          }
          k = p  ; 
    }
    cout<<"\nHavent name was "<<name0<<" in LIST employee! "; 
}
int sum(list &l){
    int sum = 0 ;
    for(NODE *p=l.head;p;p=p->next){
        sum+=1 ; 
    }
    return sum ;  
}
void information_of_hightest_salary(LIST l){
        int sum = l.head->data.salary;
        NODE *p ;   
        for(p=l.head->next;p;p=p->next)
                      if(sum < p->data.salary) sum = p->data.salary ;  
        for(p=l.head;p;p=p->next){
            if(sum == p->data.salary){
                    cout<<"infor highest salary: ";
                    Displa(p->data); 
                    cout<<endl; 
            }
        }
} 
void one_infor(LIST l,string name0){
       for(NODE *p=l.head;p;p=p->next){
            if(p->data.name == name0){
                cout<<"\nFIND name! "<<endl ; 
                    Displa(p->data);
                     return ; 
            }
       }
}
int menu()
{
    int z;
    cout << "\nEmployee manager";
    cout << "\n1. Enter list employee.";
    cout << "\n2. Display list employee.";
    cout << "\n3. Sort List of salary low and low. ";
    cout << "\n4. Delete follow id of employee. ";
    cout << "\n5. Add employee. ";
    cout << "\n6. Fix information. ";
    cout << "\n7. Sum of employee in list. ";
    cout << "\n8. Information of employee have highest salary. ";
    cout << "\n9. Display one information of employee. ";
    cout << "\n0. Exit. ";
    do
    {
        cout << "\nEnter request: ";
        cin >> z;
        if (z > 10 || z < 0)
            cout << "Wrong! " << endl;
    } while (z > 10 || z < 0);
    return z;
}
int main()
{   int check = 1,luck ; 
    ee tmp; 
    string namefix; 
    NODE *p ;  
    LIST   l ;   
    while (check)
    {
          luck =  menu(); 
          if(!luck) {
               freedom(l);
               return 0 ; 
          }
        switch(luck)
           { 
              case 1: 
               Input(l);
               break ; 
              case 2:
               Output(l);
              break ;  
             case 3: 
               Sort(l);
               break; 
               case 4:
                  int id ; 
                  cout<<"ENter id to delete: "; 
                  cin>>id; 
                  delete_node(l,id); 
                break ; 
                case 5: 
                Enter_employee(tmp); 
                p =  getNode(tmp); 
                addTail(l,p); 
                break ; 
                case 6:  
                 cout<<"\nENter your name u want find";
                delete_fflush(); 
                getline(cin,namefix); 
                fix_in4(l,namefix);
                break ; 
                 case 7: 
                    cout<<"\nALL of employee in company is: "<<sum(l); 
                    break ; 
                case 8:
                  information_of_hightest_salary(l); 
                  break ; 
                case 9: 
                   string zz ; 
                    cout<<"\nEnter name u want find: ";
                    delete_fflush();
                    getline(cin,zz);
                    one_infor(l,zz); 
                    break ;  

        }
    }
}