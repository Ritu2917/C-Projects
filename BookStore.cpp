#include<iostream>
#include<math.h>
using namespace std;
class node
{
	friend class book;
public:
	string name,author,lang;
	int stock,price,isbn;
	node *next;
public:
	node(string n,string a,string l,int s,int p,int i)
{
		name=n;
		author=a;
		lang=l;
		stock=s;
		price=p;
		isbn=i;
		next=NULL;
}
};
class book
{
 node *head,*temp;
public:
 book()
{
	 head=NULL;
}
 void create()
 {
	 string n,a,l;
	 int s,p,i;
	 char ch;
	 do
	 {
	 cout<<"Enter Book Name:"<<endl;
	 cin>>n;
	 cout<<"Enter Author Name:"<<endl;
	 cin>>a;
	 cout<<"Enter Language:"<<endl;
	 cin>>l;
	 cout<<"Enter Stock:"<<endl;
	 cin>>s;
	 cout<<"Enter Price:"<<endl;
	 cin>>p;
	 cout<<"Enter ISBN:"<<endl;
	 cin>>i;
	 if(checkisbn(i)==0)
	 {
		 cout<<"Enter Valid ISBN(5 Digit ISBN):"<<endl;
		 cin>>i;
	 }
	 temp=new node(n,a,l,s,p,i);
	 if(head==NULL)
	 {
		 head=temp;
	 }
	 else
	 {
		 node *ptr=head;
		 while(ptr->next!=NULL)
		 {
			 ptr=ptr->next;
		 }
		 ptr->next=temp;
		 temp->next=NULL;
	 }
	 cout<<"Press 'y/'Y' If You Want To Add More Books Else Press 'n'/'N' "<<endl;
	 cin>>ch;
	 }while(ch=='y'||ch=='Y');
 }
 void display()
 {
	 int n=0;
	 node *ptr=head;
	 cout<<"BNo."<<"\t\t"<<"BName"<<"\t\t"<<"AName"<<"\t\t"<<"Lang"<<"\t\t"<<"Stock"<<"\t\t"<<"Price"<<"\t\t"<<"ISBN"<<endl;
	 while(ptr!=NULL)
	 {
		 n++;
		 cout<<n<<"\t\t"<<ptr->name<<"\t\t"<<ptr->author<<"\t\t"<<ptr->lang<<"\t\t"<<ptr->stock<<"\t\t"<<ptr->price<<"\t\t"<<ptr->isbn<<endl;
		 ptr=ptr->next;
	 }
 }
 int search(string n,int i)
 {
	 node *ptr=head;
	 int flag=0;
	 while(ptr!=NULL)
	 {
		 if(ptr->name==n&&ptr->isbn==i)
		 {
			 flag=1;
			 cout<<"*****YES! The Book Is Present*****"<<endl;
			 return 1;
		 }
		 ptr=ptr->next;
	 }
	 if(flag==0)
		 cout<<"*****SORRY!!!... The Book Is Not Available*****"<<endl;
	    return 0;
 }
 void remove(string n,int i)
 {
	 int p=0;
	 //cout<<"Details Of The Books That You Wanted To Remove Are:"<<endl;
	 if(search(n,i))
	 {
		 node *ptr=head,*prev;
		 while(ptr!=NULL)
		 {
             if(ptr->name==n&&ptr->isbn==i)
             {
            	 if(p==0)
            	{
            	 	head=ptr->next;
            	    delete(ptr);
            	 }
            	 else
            	 {
            		 prev->next=ptr->next;
            		 delete(ptr);
            	 }

             }
             prev=ptr;
             ptr=ptr->next;
             p++;
		 }
	 }
 }
 void purchase()
 {
	 int sum=0;
	 char ch;
	 string n;
	 int i;
	 int s;
     do
     {
	 cout<<"Enter Book Name:"<<endl;
	 cin>>n;
	 cout<<"Enter ISBN:"<<endl;
	cin>>i;
	if(checkisbn(i)==0)
		 {
			 cout<<"Enter Valid ISBN(5 Digit ISBN):"<<endl;
			 cin>>i;
		 }
	if(search(n,i))
	{

		node *ptr=head;
		cout<<"How Many Copies Do You Want?"<<endl;
		cin>>s;
			cout<<"BName"<<"\t\t"<<"Price"<<"\t\t"<<"Total Amt"<<endl;
		while(ptr->next!=NULL)
		{
			if(ptr->name==n&&ptr->isbn==i)
			{
				if((ptr->stock)<s)
						{
							cout<<"*****Out Of Stock...*****"<<endl;
						}
				else
				{
				cout<<ptr->name<<"\t\t"<<ptr->price<<"\t\t"<<ptr->price*s<<endl;
				sum=sum+ptr->price*s;
				ptr->stock=(ptr->stock)-s;
				}
			}
			ptr=ptr->next;
		}

	}
	else
	{
		cout<<"*****Sorry!!!... The Book Is Not Available...*****"<<endl;
	}
	cout<<"Do You Want TO Purchase More Books?If Yes Press 'y/Y' Else Press 'n/N' "<<endl;
					cin>>ch;
	}while(ch=='y'||ch=='Y');
     cout<<"Grand Total:"<<sum<<endl;
     cout<<"\n";
     cout<<"Please Visit Again"<<endl;
 }
 void listbyauthor(string a)
 {
	 int flag=0;
	 node *ptr=head;
	 cout<<"BName"<<"\t\t"<<"AName"<<"\t\t"<<"Lang"<<"\t\t"<<"Stock"<<"\t\t"<<"Price"<<"\t\t"<<"ISBN"<<endl;
	 while(ptr!=NULL)
	 {

		 if(ptr->author==a)
		 {
			 flag=1;
			 cout<<ptr->name<<"\t\t"<<ptr->author<<"\t\t"<<ptr->lang<<"\t\t"<<ptr->stock<<"\t\t"<<ptr->price<<"\t\t"<<ptr->isbn<<endl;
		 }
		 ptr=ptr->next;
	 }
	 if(flag==0)
	 {
		 cout<<"*****Sorry!!!... The Book Is Not Available*****"<<endl;
	 }
 }
 void listbylang(string l)
  {
 	 int flag=0;
 	 node *ptr=head;
 	cout<<"BName"<<"\t\t"<<"AName"<<"\t\t"<<"Lang"<<"\t\t"<<"Stock"<<"\t\t"<<"Price"<<"\t\t"<<"ISBN"<<endl;
 	 while(ptr!=NULL)
 	 {
 		 if(ptr->lang==l)
 		 {
 			 flag=1;
 			cout<<ptr->name<<"\t\t"<<ptr->author<<"\t\t"<<ptr->lang<<"\t\t"<<ptr->stock<<"\t\t"<<ptr->price<<"\t\t"<<ptr->isbn<<endl;
 		 }
 		 ptr=ptr->next;
 	 }
 	 if(flag==0)
 	 {
 		 cout<<"*****Sorry!!!... The Book Is Not Available*****"<<endl;
 	 }
  }

void update(string n,int is)
{
	if(search(n,is))
	{
		int st;
		cout<<"Enter The New Stock:"<<endl;
		cin>>st;
		node *ptr=head;
		while(ptr!=NULL)
		{
			if(ptr->name==n&&ptr->isbn==is)
			{

				ptr->stock=ptr->stock+st;
			}
			ptr=ptr->next;
		}
	}


}
void sort()
	{
		node *i,*j;
		for(i=head;i->next!=NULL;i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->isbn>j->isbn)
				{
					int is=i->isbn;
					int p=i->price;
					int s=i->stock;
					string n=i->name;
					string a=i->author;
					string l=i->lang;
					i->isbn=j->isbn;
					j->isbn=is;
					i->price=j->price;
					j->price=p;
					i->stock=j->stock;
					j->stock=s;
					i->name=j->name;
					j->name=n;
					i->author=j->author;
					j->author=a;
					i->lang=j->lang;
					j->lang=l;
				}
			}
		}
	}
   int checkisbn(int i)
   {
	   int no=log10(i)+1;
	   if(no!=5)
	   {
		   return 0;
	   }
	   else
		   return 1;
   }
};
int main()
{
	book b,b1;
	string password;
	int i;
	string n,a,l;
	 int is;
	string apassword="BookStore";
	cout << "\n*********************** BOOKSHOP DATA MANAGEMENT ********************\n";
	cout<<"Enter Password\n";
	cin>>password;
	if(password!=apassword)
	{
		cout<<"Password Invalid...Try Again\n";
		cin>>password;
		while(password!=apassword)
		{
			cout<<"Password Invalid...Try Again\n";
			cin>>password;
		}
	}

		    cout<<"Password Accepted\n";
		    cout << "\n*********************** WELCOME TO BOOK SHOP ***********************\n";
		do
		{
			cout<<"\n";
    cout<<"BOOK STOP MENU:"<<endl;
    cout<<"Press 1 To Add Books To Book shop:"<<endl;
    cout<<"Press 2 To Display Details Of The Books:"<<endl;
    cout<<"Press 3 To Search For A Particular Book:"<<endl;
    cout<<"Press 4 To Remove A Particular Book:"<<endl;
    cout<<"Press 5 To Purchase Book:"<<endl;
    cout<<"Press 6 To Update Stock Of Books:"<<endl;
    cout<<"Press 7 To Sort Books:"<<endl;
    cout<<"Press 8 To Know Books By A Particular Author:"<<endl;
    cout<<"Press 9 To Know Books By A Particular Language :"<<endl;
    cout<<"Enter Your Choice"<<endl;
    cin>>i;
    switch(i)
    {
    case 1:b.create();
           break;
    case 2:b.display();break;
    case 3:cout<<"Enter Name Of Book And Its ISBN You Want To Search For:"<<endl;
           cout<<"Book Name?"<<endl;
           cin>>n;
           cout<<"ISBN?"<<endl;
           cin>>is;
           if(b.checkisbn(is)==0)
           	 {
           		 cout<<"Enter Valid ISBN(5 Digit ISBN):"<<endl;
           		 cin>>is;
           	 }
    	   b.search(n,is);break;
    case 4:	cout<<"Enter Name Of Book And Its ISBN You Want To Remove:"<<endl;
            cout<<"Book Name?"<<endl;
            cin>>n;
            cout<<"ISBN?"<<endl;
            cin>>is;
            if(b.checkisbn(is)==0)
                       	 {
                       		 cout<<"Enter Valid ISBN(5 Digit ISBN):"<<endl;
                       		 cin>>is;
                       	 }
            b.remove(n, is);
            break;
    case 5: cout<<"Bill:"  <<endl;
    	   b.purchase();break;
    case 6:cout<<"Enter The ISBN And Name Of The Book Whose Stock You Want to Update:"<<endl;
           cout<<"ISBN:"<<endl;
           cin>>is;
           if(b.checkisbn(is)==0)
                      	 {
                      		 cout<<"Enter Valid ISBN(5 Digit ISBN):"<<endl;
                      		 cin>>is;
                      	 }
           cout<<"NAME:"<<endl;
           cin>>n;
           b.update(n,is);
    	   break;
    case 7:cout<<"Sorted Book Are:"<<endl;
           b.sort();
           b.display();
    	   break;
    case 8:cout<<"Enter Author Name:"<<endl;
           cin>>a;
    	   b.listbyauthor(a);break;
    case 9:cout<<"Enter Language:"<<endl;
           cin>>l;
           b.listbylang(l);


    }

		}while(i>0&&i<=9);

return 0;
}
