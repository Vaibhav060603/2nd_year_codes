#include<fstream>
#include<iostream>
#include<string>
using namespace std;




int main()
{
int opt;
fstream f;

int i;
string s;

while(1)
{
cout<<"-----------------You want to perform which operation----------- "<<endl;
cout<<"1. Create a database of large number of students."<<endl<<"2. Add a student data in existing file."<<endl<<"3. Display a student data."<<endl<<"4. Display whole database."<<endl<<"5. Delete a student."<<endl<<"6. Exit."<<endl;
cin>>opt;


	if(opt==1)
	{
		int n;
		cout<<"How many number of student's database you want to make :";
		cin>>n;
		
		int roll;
		string name;
		long mobile;
		int i;
		f.open("file1.txt",ios::out|ios::app);
		for(i=1;i<=n;i++)
		{
			cout<<"Enter roll number of student "<<i<<" : ";
			cin>>roll;
			cout<<"Enter name of student "<<i<<" : ";
			cin>>name;
			cout<<"Enter mobile number of student "<<i<<" : ";
			cin>>mobile;
			
			
			
			f<<roll<<"  "<<name<<"  "<<mobile<<endl;
		}
		f.close();
	}
	
	if(opt==2)
	{
		int roll;
		string name,s;
		long mobile;
		int i;
		f.open("file1.txt",ios::out|ios::app);
		        cout<<"Enter roll number of student "<<": ";
			cin>>roll;
			cout<<"Enter name of student "<<": ";
			cin>>name;
			cout<<"Enter mobile number of student "<<": ";
			cin>>mobile;
			
			for(i=1;i<=10;i++)
			{
				if(i==roll)
				{
					f<<roll<<"  "<<name<<"  "<<mobile<<endl;
				}
			}
		f.close();
	}
	
	if(opt==3)
	{
		int roll;
		cout<<"Enter the roll number you want to display :";
		cin>>roll;
		int i;
		string s;
		f.open("file1.txt",ios::in|ios::app);
		for(i=1;getline(f,s) && i<=10;i++)
		{
			if(i==roll)
			{
				cout<<s<<endl;
			}
		}
		f.close();
		
	}
	
	if(opt==4)
	{
		int roll=1;
		int i;
		string s;
		
		f.open("file1.txt",ios::in|ios::app);
		
		for(i=1;getline(f,s) && i<=10;i++)
		{
			if(i==roll)
			{
				cout<<s<<endl;
			}
			roll+=1;
		}
		f.close();
		
	}
	
	if(opt==6)
	{
		break;
	}
	

}


return 0;




/*
string a;
int i;
fstream f;
f.open("file1.txt",ios::out|ios::ate);
f<<"Hello world my friend  "<<endl;
f<<"Hello world   "<<endl;
f<<"how are you"<<endl;
f.close();


f.open("file1.txt",ios::in);
for(i=1;getline(f,a) && i<=3;i++)
{
	if(i==2 || i==3)
	{
		cout<<a<<endl;
	}
}

*/



}
