/*
 * Airlines.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: RUTUJA
 */




#include<iostream>
#include<iomanip>

using namespace std;

class Flight
{
	string fno;
	float priceEco;
	float priceBuss;
	string board;
	string dest;
	int Eseat;
	int Bseat;
	string timeA,timeD;
public:
	Flight()
	{
		fno=" ";
		priceEco=0;
		priceBuss=0;
		board=" ";
		dest=" ";
		Eseat=20;
		Bseat=8;
		timeA=" ";
		timeD=" ";
	}

	static void flightDatabase(Flight f[10])
	{
		f[0].fno="AI9887";
		f[0].board="NASIK";
		f[0].dest="PUNE";
		f[0].priceEco=1500;
		f[0].priceBuss=3500;
		f[0].timeD="08:30";
		f[0].timeA="09:30";

		f[1].fno="AI9999";
		f[1].board="PUNE";
		f[1].dest="NASIK";
		f[1].priceEco=2000;
		f[1].priceBuss=4000;
		f[1].timeD="14:55";
		f[1].timeA="15:45";

		f[2].fno="AI9886";
		f[2].board="DELHI";
		f[2].dest="MUMBAI";
		f[2].priceEco=5000;
		f[2].priceBuss=7000;
		f[2].timeD="04:55";
		f[2].timeA="06:05";

		f[3].fno="AI9868";
		f[3].board="MUMBAI";
		f[3].dest="DELHI";
		f[3].priceEco=5000;
		f[3].priceBuss=7000;
		f[3].timeD="07:00";
		f[3].timeA="08:40";

		f[4].fno="AI9985";
		f[4].board="KOLKATA";
		f[4].dest="MUMBAI";
		f[4].priceEco=8000;
		f[4].priceBuss=10000;
		f[4].timeD="10:10";
		f[4].timeA="13:00";

		f[5].fno="AI9958";
		f[5].board="MUMBAI";
		f[5].dest="KOLKATA";
		f[5].priceEco=6500;
		f[5].priceBuss=8500;
		f[5].timeD="01:30";
		f[5].timeA="03:50";

		f[6].fno="AI9742";
		f[6].board="BANGLORE";
		f[6].dest="DELHI";
		f[6].priceEco=6400;
		f[6].priceBuss=8400;
		f[6].timeD="12:40";
		f[6].timeA="03:30";

		f[7].fno="AI9472";
		f[7].board="CHENNAI";
		f[7].dest="MUMBAI";
		f[7].priceEco=5300;
		f[7].priceBuss=7300;
		f[7].timeD="08:40";
		f[7].timeA="10:40";

		f[8].fno="AI4622";
		f[8].board="DELHI";
		f[8].dest="CHENNAI";
		f[8].priceEco=6500;
		f[8].priceBuss=8500;
		f[8].timeD="17:20";
		f[8].timeA="20:00";

		f[9].fno="AI8652";
		f[9].board="DELHI";
		f[9].dest="KOLKATA";
		f[9].priceEco=5700;
		f[9].priceBuss=7700;
		f[9].timeD="19:25";
		f[9].timeA="21:45";
	}

	static bool isAvailable(string b,string d,Flight f[10])
	{
		for(int i=0;i<10;i++)
		{
			if(f[i].board==b && f[i].dest==d)
				return true;
		}
		return false;
	}

	static int getFlight(Flight f[10],string fn)
	{
		for(int i=0;i<10;i++)
		{
			if(f[i].fno==fn)
				return i;
		}
		return 0;

	}

	static void show(string b,string d,Flight f[10])
	{
		for(int i=0;i<10;i++)
		{
			if(f[i].board==b && f[i].dest==d)
			{
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
				cout<<"FLIGHT DETAILS: "<<endl;
				cout<<"FLIGHT NO: "<<f[i].fno<<endl;
				cout<<"BOARDING: "<<f[i].board<<" DEPARTURE AT "<<f[i].timeD<<endl;
				cout<<"DESTINATION: "<<f[i].dest<<" ARRIVAL AT "<<f[i].timeA<<endl;
				cout<<"TICKET PRICE FOR ECONOMY CLASS: "<<f[i].priceEco<<endl;
				cout<<"SEATS AVAILABLE: "<<25-f[i].Eseat<<endl;
				cout<<"TICKET PRICE FOR BUSINSS CLASS: "<<f[i].priceBuss<<endl;
				cout<<"SEATS AVAILABLE: "<<10-f[i].Bseat<<endl;
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
			}
		}
	}

	static string retFno(string b,string d,Flight f[10])
	{
		for(int i=0;i<10;i++)
		{
			if(f[i].board==b && f[i].dest==d)
				return f[i].fno;
		}
		return NULL;
	}

	static void seatChart(Flight f[10],string fn,string c,int arrE[10][5],int arrB[10][2])
	{
		int i=getFlight(f,fn);
		cout<<endl;
		cout<<"*************************************************************************************************************"<<endl;
		cout<<endl;
		cout<<setw(40)<<"SEAT OCCUPIED"<<setw(40)<<"SEAT VACANT"<<endl;
		cout<<setw(40)<<"   | A01 |   "<<setw(40)<<"  | A01 |  "<<endl;
		cout<<setw(40)<<"   | ==  |   "<<setw(40)<<"  |     |  "<<endl;
		cout<<endl;
		cout<<"*************************************************************************************************************"<<endl;
		cout<<endl;
		if(c=="ECONOMY")
		{
			cout<<setw(70)<<"| A01  A02  A03 \t  A04  A05  |"<<endl;
			cout<<setw(70)<<"| ==   ==   ==  \t  ==   ==   |"<<endl;
			cout<<setw(70)<<"| B06  B07  B08 \t  B09  B10  |"<<endl;
			cout<<setw(70)<<"| ==   ==   ==  \t  ==   ==   |"<<endl;
			cout<<setw(70)<<"| C11  C12  C13 \t  C14  C15  |"<<endl;
			cout<<setw(70)<<"| ==   ==   ==  \t  ==   ==   |"<<endl;
			cout<<setw(70)<<"| D16  D17  D18 \t  D19  D20  |"<<endl;
			cout<<setw(70)<<"| ==   ==   ==  \t  ==   ==   |"<<endl;
			cout<<setw(70)<<"| E21  E22  E23 \t  E24  E25  |"<<endl;
			cout<<setw(42)<<"| ";
			for(int j=0;j<5;j++)
			{
				if(arrE[i][j]==1 && j==2)
					cout<<"==  \t  ";
				else if(arrE[i][j]==1)
					cout<<"==   ";
				else if(arrE[i][j]==0 && j==2)
					cout<<"    \t  ";
				else
					cout<<"     ";
			}
			cout<<"|"<<endl;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
		}
		else
		{
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			cout<<setw(63)<<"| A01 \t  A02 |"<<endl;
			cout<<setw(63)<<"| ==  \t  ==  |"<<endl;
			cout<<setw(63)<<"| B03 \t  B04 |"<<endl;
			cout<<setw(63)<<"| ==  \t  ==  |"<<endl;
			cout<<setw(63)<<"| C05 \t  C06 |"<<endl;
			cout<<setw(63)<<"| ==  \t  ==  |"<<endl;
			cout<<setw(63)<<"| D07 \t  D08 |"<<endl;
			cout<<setw(63)<<"| ==  \t  ==  |"<<endl;
			cout<<setw(63)<<"| E09 \t  E10 |"<<endl;
			cout<<setw(51)<<"| ";
			for(int j=0;j<2;j++)
			{
				if(arrB[i][j]==1 && j==0)
					cout<<"==  \t  ";
				else if(arrB[i][j]==1)
					cout<<"==  ";
				else if(arrB[i][j]==0 && j==0)
					cout<<"    \t  ";
				else
					cout<<"    ";
			}
			cout<<"|"<<endl;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
		}
	}

	static void updateSeatAdd(Flight f[10],string fn,string c)
	{
		int i=getFlight(f,fn);
		if(c=="ECONOMY")
			f[i].Eseat++;
		else
			f[i].Bseat++;
	}

	static void updateSeatRemove(Flight f[10],string fn,string c)
	{
		int i=getFlight(f,fn);
		if(c=="ECONOMY")
			f[i].Eseat--;
		else
			f[i].Bseat--;
	}

	static string retTimeD(Flight f[10],string fn)
	{
		int i=getFlight(f,fn);
		return f[i].timeD;
	}

	static string retTimeA(Flight f[10],string fn)
	{
		int i=getFlight(f,fn);
		return f[i].timeA;
	}
};

class Passenger
{
	string seat;
	string name,flightp;
	int age;
	string boarding,destination;
	string Class;
	string arrive,depart;
	Passenger *next;
	friend class Airlines;
public:

	Passenger()
	{
		flightp=" ";
		seat=" ";
		name=" ";
		age=0;
		boarding=" ";
		destination=" ";
		Class=" ";
		depart=" ";
		arrive=" ";
		next=NULL;
	}
	Passenger(string n,int a,string b,string d,string c,string fp,string s,string td,string ta)
	{
		flightp=fp;
		seat=s;
		name=n;
		age=a;
		boarding=b;
		destination=d;
		Class=c;
		depart=td;
		arrive=ta;
		next=NULL;
	}
};

class Airlines
{
	Passenger *front,*rear;
	int countE[10],countB[10];
public:
	Airlines()
    {
		front=rear=NULL;
		for(int i=0;i<10;i++)
		{
			countE[i]=20;
			countB[i]=8;
		}
    }

	bool isEmpty()
	{
		if(front==NULL)
			return true;
		return false;
	}

	bool isFullE(int pos)
	{
		if(countE[pos]==25)
			return true;
		return false;
	}

	bool isFullB(int pos)
	{
		if(countB[pos]==10)
			return true;
		return false;
	}

	void add(string n,int a,string b,string d,string c,string fp,string s,string td,string ta,int pos)
	{
		if(c=="ECONOMY")
		{
			if(isFullE(pos))
			{
				cout<<"BOOKINGS OF ECONOMY CLASS ARE FULL"<<endl;
			}
			else
			{
				countE[pos]++;
				Passenger *tmp=new Passenger(n,a,b,d,c,fp,s,td,ta);
				if(isEmpty())
				{
					front=rear=tmp;
				}
				else
				{
					rear->next=tmp;
					rear=rear->next;
				}
				cout<<"TICKET BOOKED"<<endl;
			}
		}
		else
		{
			if(isFullB(pos))
			{
				cout<<"BOOKINGS OF BUSINESS CLASS ARE FULL"<<endl;
			}
			else
			{
				countB[pos]++;
				Passenger *tmp=new Passenger(n,a,b,d,c,fp,s,td,ta);
				if(isEmpty())
				{
					front=rear=tmp;
				}
				else
				{
					rear->next=tmp;
					rear=rear->next;
				}
				cout<<"TICKET BOOKED"<<endl;
			}
		}
	}

	void remove(string fp,string s,string c,int pos)
	{
		Passenger *prev,*curr,*temp;
		curr=front->next;
		prev=front;
		if(front==NULL)
			cout<<"LIST IS EMPTY"<<endl;
		else
		{
			if(front->flightp==fp && front->seat==s && front->Class==c)
			{
				if(c=="ECONOMY")
					countE[pos]--;
				else
					countB[pos]--;
				temp=front;
				front=front->next;
				delete temp;
			}
			else
				{
				    while(curr!=NULL)
				    {
				    	if(curr->flightp==fp && curr->seat==s && curr->Class==c)
				    	{
							if(c=="ECONOMY")
								countE[pos]--;
							else
								countB[pos]--;
				    		temp=curr;
				    		prev->next=curr->next;
				    		break;
				    	}
				    	prev=prev->next;
				    	curr=curr->next;
				    }
				    delete temp;
	    	    }
			cout<<"BOOKING CANCELLED SUCCESSFULLY"<<endl;
		}
	}

	int search(string fp,string s,string c)
	{
		if(isEmpty())
			return 0;
		else
		{
			Passenger *ptr;
			int flag=0;
			ptr=front;
			while(ptr!=NULL)
			{
				if(ptr->flightp==fp && ptr->seat==s && ptr->Class==c)
				{
					flag=1;
				}
				ptr=ptr->next;
			}
			if(flag==0)
				return 0;
			else
				return 1;
		}
	}

	void display(string fp,string s,string c)
	{
		if(isEmpty())
			cout<<"Queue is Empty"<<endl;
		else
		{
			Passenger *ptr;
			ptr=front;
			while(ptr!=NULL)
			{
				if(ptr->flightp==fp && ptr->seat==s && ptr->Class==c)
				{
					cout<<endl;
					cout<<"*************************************************************************************************************"<<endl;
					cout<<endl;
					cout<<"TICKET DETAILS:"<<endl;
					cout<<"Flight No.: "<<ptr->flightp<<endl;
					cout<<"Passenger Name: "<<ptr->name<<endl;
					cout<<"Passenger Age: "<<ptr->age<<endl;
					cout<<"Class: "<<ptr->Class<<endl;
					cout<<"Seat No.: "<<ptr->seat<<endl;
					cout<<"From: "<<ptr->boarding<<" Departure At "<<ptr->depart<<endl;
					cout<<"To: "<<ptr->destination<<" Arrival At "<<ptr->arrive<<endl;
					cout<<endl;
					cout<<"*************************************************************************************************************"<<endl;
					cout<<endl;
					break;
				}
				ptr=ptr->next;
			}
		}
	}
};

int main()
{
	Flight f[10];
	Flight::flightDatabase(f);
	Airlines A;
	int a;
	int arrE[10][5];
	int arrB[10][2];
	string n,b,d,c,s,fn,ta,td;
	int ch=0;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<5;j++)
			arrE[i][j]=0;
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<2;j++)
			arrB[i][j]=0;
	}
	do
	{
		cout<<endl;
		cout<<"*************************************************************************************************************"<<endl;
		cout<<endl;
		cout<<setw(40)<<" "<<"WELCOME TO AIR-INDIA AIRLINES"<<endl;
		cout<<endl;
		cout<<"*************************************************************************************************************"<<endl;
		cout<<endl;
		cout<<setw(40)<<" "<<"1. BOOK TICKET"<<endl;
		cout<<setw(40)<<" "<<"2. CANCEL TICKET"<<endl;
		cout<<setw(40)<<" "<<"3. DISPLAY THE DETAILS OF TICKET"<<endl;
		cout<<setw(40)<<" "<<"4. EXIT"<<endl;
		cout<<endl;
		cout<<"*************************************************************************************************************"<<endl;
		cout<<endl;
		cout<<"ENTER YOUR CHOICE: ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			cout<<"ENTER BOARDING AND DESTINATION PLACES (ENTER IN BLOCK LETTERS ONLY): "<<endl;
			cout<<"BOARDING: ";
			cin>>b;
			cout<<"DESTINATION: ";
			cin>>d;
			if(Flight::isAvailable(b,d,f))
			{
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
				cout<<"FLIGHT IS AVAILABLE"<<endl;
				Flight::show(b,d,f);
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
				cout<<"ENTER PASSENGER DETAILS (ENTER IN BLOCK LETTERS ONLY): "<<endl;
				cout<<"NAME: ";
				getline(cin,n);
				getline(cin,n);
				cout<<"AGE: ";
				cin>>a;
				cout<<"CLASS (ECONOMY/BUSINESS): ";
				cin>>c;
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
				if(c=="ECONOMY")
				{
					fn=Flight::retFno(b,d,f);
					int pos=Flight::getFlight(f,fn);
					if(A.isFullE(pos))
						cout<<"SEATS OF ECONOMY CLASS ARE FULL"<<endl;
					else
					{
						td=Flight::retTimeD(f,fn);
						ta=Flight::retTimeA(f,fn);
						cout<<"SEATS AVAILABLE: "<<endl;
						Flight::seatChart(f,fn,c,arrE,arrB);
						cout<<"ENTER SEAT NO.: ";
						cin>>s;
						cout<<endl;
						cout<<"*************************************************************************************************************"<<endl;
						cout<<endl;
						if(s=="E21" || s=="E22" || s=="E23" || s=="E24" || s=="E25")
						{
							A.add(n,a,b,d,c,fn,s,td,ta,pos);
							A.display(fn,s,c);
							Flight::updateSeatAdd(f,fn,c);
							if(s=="E21")
								arrE[pos][0]=1;
							else if(s=="E22")
								arrE[pos][1]=1;
							else if(s=="E23")
								arrE[pos][2]=1;
							else if(s=="E24")
								arrE[pos][3]=1;
							else
								arrE[pos][4]=1;
						}
						else
							cout<<"INVALID SEAT"<<endl;
					}
				}
				else if(c=="BUSINESS")
				{
					fn=Flight::retFno(b,d,f);
					int pos=Flight::getFlight(f,fn);
					if(A.isFullB(pos))
						cout<<"SEATS OF BUSINESS CLASS ARE FULL"<<endl;
					else
					{
						td=Flight::retTimeD(f,fn);
						ta=Flight::retTimeA(f,fn);
						cout<<"SEATS AVAILABLE: "<<endl;
						Flight::seatChart(f,fn,c,arrE,arrB);
						cout<<"ENTER SEAT NO.: ";
						cin>>s;
						cout<<endl;
						cout<<"*************************************************************************************************************"<<endl;
						cout<<endl;
						if(s=="E09" || s=="E10")
						{
							A.add(n,a,b,d,c,fn,s,td,ta,pos);
							A.display(fn,s,c);
							Flight::updateSeatAdd(f,fn,c);
							if(s=="E09")
								arrB[pos][0]=1;
							else if(s=="E10")
								arrB[pos][1]=1;
						}
						else
							cout<<"INVALID SEAT"<<endl;
					}
				}
				else
					cout<<"WRONG INPUT!"<<endl;
			}
			else
			{
				cout<<endl;
				cout<<"*************************************************************************************************************"<<endl;
				cout<<endl;
				cout<<"FLIGHT NOT AVAILABLE"<<endl;
			}
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			break;
		case 2:
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			cout<<"ENTER FLIGHT NO.: ";
			cin>>fn;
			cout<<"ENTER SEAT NO.: ";
			cin>>s;
			cout<<"ENTER CLASS: ";
			cin>>c;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			if(A.search(fn,s,c))
			{
				if(c=="ECONOMY")
				{
					int pos=Flight::getFlight(f,fn);
					if(s=="E21")
						arrE[pos][0]=0;
					else if(s=="E22")
						arrE[pos][1]=0;
					else if(s=="E23")
						arrE[pos][2]=0;
					else if(s=="E24")
						arrE[pos][3]=0;
					else
						arrE[pos][4]=0;
				}
				else if(c=="BUSINESS")
				{
					int pos=Flight::getFlight(f,fn);
					if(s=="E09")
						arrB[pos][0]=0;
					else if(s=="E10")
						arrB[pos][1]=0;
				}
				Flight::updateSeatRemove(f,fn,c);
				int pos=Flight::getFlight(f,fn);
				A.remove(fn,s,c,pos);
			}
			else
				 cout<<"INVALID FLIGHT OR SEAT NO."<<endl;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			break;
		case 3:
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			cout<<"ENTER FLIGHT NO.: ";
			cin>>fn;
			cout<<"ENTER SEAT NO.: ";
			cin>>s;
			cout<<"ENTER CLASS: ";
			cin>>c;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			if(A.search(fn,s,c))
				A.display(fn,s,c);
			else
				cout<<"INVALID FLIGHT OR SEAT NO."<<endl;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			break;
		case 4:
			exit(0);
		default:
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
			cout<<"WRONG CHOICE!!"<<endl;
			cout<<endl;
			cout<<"*************************************************************************************************************"<<endl;
			cout<<endl;
		}
	}while(ch);
	return 0;
}
