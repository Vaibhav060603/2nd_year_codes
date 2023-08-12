#include<iostream>
#include<string>
#include<stack>
using namespace std;

class node
{
public:
string data;
node *rnext;
node *lnext;

	node()
	{
		this->data=" ";
		this->rnext=NULL;
		this->lnext=NULL;	
	}
	
	node(string data)
	{
		this->data=data;
		this->rnext=NULL;
		this->lnext=NULL;	
	}
	
	
};

class btree:public node
{
public:
node *root;
	btree()
	{
		root=NULL;
	}
	
	void insert(node *toins)
	{
	char dir;
	
		if(root==NULL)
		{
			root=toins;
			cout<<"Root created."<<endl;
		}
	
		else
		{
		node *temp=root;
			do
			{
				cout<<"In which direction you want to go.(R/L)"<<endl;
				cin>>dir;
			
					if(dir=='R' || dir=='r')
					{
						if(temp->rnext==NULL)
						{
							cout<<"Node inserted at right of "<<temp->data<<endl;
							temp->rnext=toins;
							break;
						}
						
						else
						{
							temp=temp->rnext;
						}
						
					}
			
					if(dir=='L' || dir=='l')
					{
						if(temp->lnext==NULL)
						{
							cout<<"Node inserted at left of "<<temp->data<<endl;
							temp->lnext=toins;
							break;
						}
						
						else
						{
							temp=temp->rnext;
						}
					}
					
			}
			while(temp!=NULL);
			
			
		}
	}
	
	void print(node *root)
	{
		int ip;
		if(root==NULL)
		{
			cout<<"tree does not exist."<<endl;
			
		}
		
		
		else
		{
		node *temp=root;
		stack<node *> s;
		cout<<"You want data in infix aur prefix order.(1.(infix) OR 2.(prefix))"<<endl,
		cin>>ip;
		
			
				if(ip==1)
				{
					do
					{
						while(temp!=NULL)
						{
							s.push(temp);
							temp=temp->lnext;
						}
		
						if(temp==NULL)
						{
							temp=s.top();
							s.pop();
							cout<<temp->data<<endl;
							temp=temp->rnext;
						}
					}while(temp!==NULL || s.empty()==0)
				}
		
				if(ip==2)
				{
					do
					{
						while(temp!=NULL)
						{
							cout<<temp->data<<endl;
							s.push(temp);
							temp=temp->lnext;
						}
		
						if(temp==NULL)
						{
							temp=s.top();
							s.pop();
							temp=temp->rnext;
						}
					}while(temp!=NULL || s.empty()==0)
				}	
		}
	}
};


int main()
{
btree b;
node *booknam=new node("hello");
node *chapnam=new node("chapter1");
b.insert(booknam);
b.insert(chapnam);
b.print(booknam);



return 0;
}
