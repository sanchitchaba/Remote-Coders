#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
string domain="iitr.ac.in";
//STUDENT VARIABLE
class student{
	string name;
	string branch;
	string email;
	public:
		void getNameBranch();
		void assignEmail(string,string);
		void putData();
};
//FUNCTION PROTOTYPES
void heading();
void EmailGenerator();
void changeDomain();
void menu();
//MAIN
int main()
{
	menu();
	return 0;
	system("pause");
}
//MENU
void menu()
{	int choice;
	system("cls");
	cout<<setw(10)<<"MENU\n";
	cout<<"What do you wish to do?\n";
	cout<<"1.Assign email-Id to students with existing institute domain: @"<<domain;
	cout<<"\n2.Change existing institute domain\nChoice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:cout<<setw(60)<<"Program to assign Email-Id to students\n\n";
					EmailGenerator();
					break;
		case 2:changeDomain();
	}
}
//GENTERATE EMAIL ID
void EmailGenerator()
{
	system("cls");
	int n;
	cout<<"No. of Entries: ";
	cin>>n;
	cout<<"Enter Branch-acronym followed by Student names:\n";
	student s[n];
	for(int i=0;i<n;i++)
	{
		s[i].getNameBranch();
	}
	system("cls");
	heading();
	for(int i=0;i<n;i++)
	{
		s[i].putData();
	}
}
//MODIFY EXISTING DOMAIN
void changeDomain()
{
	system("cls");
	cout<<"Enter new domain\n @";
	cin>>domain;
	cout<<"Your new institute domain is @"<<domain;
	cout<<"\nEnter to any key to return to Menu";
	if(getch())
	{menu();}

}

//HEADING
void heading()
{
	cout<<setw(5)<<"NAME"<<setw(60)<<"EMAIL"<<endl;
}
//MEMBER FUNCTIONS OF STUDENT CLASS
////ASSGN EMAIL TO STUDENTS
void student::assignEmail(string branch,string name)
{
	int count=0;
	string ch;
	stringstream iss(name);
	iss>>email;
	email+="_";
	while(iss>>ch)
	{
		email+=tolower(ch[0]);
	}
	email+='@'+branch+'.'+domain;
	email[0]=tolower(email[0]);
}
////READ STUDENT NAME
void student::getNameBranch()
{
	cin>>branch;
	getline(cin,name);
	assignEmail(branch,name);
}
////OUTPUT OF STUDENT DATA
void student::putData()
{
	cout<<name<<" ";
	cout<<setw(70-name.length())<<email<<endl;
}


