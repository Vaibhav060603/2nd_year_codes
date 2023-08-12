#include<iostream>
#include<string>
using namespace std;

class client
{
public:

int id;
string name;
long number;

	client()
	{
		this->id=-1;
		this->name="nil";
		this->number=0;
	}

	client(int id, string name , long number)
	{
		this->id=id;
		this->name=name;
		this->number=number;
	}

};

class hashtab:public client
{
public:
client array[10];

//insertion
void insert(int id,string name,long number)
{

	int index=id%10;                            //hash function

	
	
	if(array[index].id==-1)
	{
		array[index].id=id;
		array[index].name=name;
		array[index].number=number;
	}
		
	else
	{
		while(array[index].id!=-1)
		{
			index+=1;
		}
		
		if(array[index].id==-1)
		{
			array[index].id=id;
			array[index].name=name;
			array[index].number=number;
		}
	}
}

//search
void search(int id)
{
	int index=id%10;
	
	if(array[index].id==id)
	{
		cout<<"Element found"<<endl;
		cout<<id<<"\n"<<name<<"\n"<<number<<endl;
	}

	else
	{
		while(array[index].id!=id)
		{
			index+=1;
		}
		
		if(array[index].id==id)
		{
			cout<<"Element found at "<<index<<" index."<<endl;
			cout<<id<<"\n"<<name<<"\n"<<number<<endl;
		}	
	
	
	}

}

//print all elements
void printal()
{
int i;
	for(i=0;i<10;i++)
	{
		cout<<"Element: "<<i+1<<endl;
		cout<<"id: "<<array[i].id<<endl;
		cout<<"name: "<<array[i].name<<endl;
		cout<<"number: "<<array[i].number<<endl;	
	}
}




//void del()


};

int main()
{
hashtab h1;
h1.insert(5,"vaibhav",7568802938);
h1.insert(15,"vaib",7568802);
h1.insert(25,"vaib",7568802);
h1.search(25);
h1.printal();


return 0;
}



