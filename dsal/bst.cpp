#include<iostream>
#include<stack>
using namespace std;

class node
{
public:

int data;
node *rnext;
node *lnext;

	node(int data)
	{
		this->data=data;
		this->rnext=NULL;
		this->lnext=NULL;	
	}
	
	node()
	{
		this->data=-1;
		this->rnext=NULL;
		this->lnext=NULL;	
	}
};


class bst:public node
{
public:
int num,i,element;
	
	node *root=new node();
		
	
	void consbst()
	{
		cout<<"Number of elements you want to get added in bst: ";
		cin>>num;
		
		
		cout<<"Enter the data of root of bst :";
		cin>>element;	
		root->data=element;
		
		node *temp=new node();	
		for(i=1;i<num;i++)
		{
			cout<<"Enter the entries you want to add in bst :";
			cin>>element;
			
			node *toins=new node(element);
			temp=root;
			do
			{	
				if(element<temp->data)
				{
					if(temp->lnext==NULL)
					{
						temp->lnext=toins;
						break;
					}
					
					else
					{
						temp=temp->lnext;
					}
				}
			
				if(element>temp->data)
				{
					if(temp->rnext==NULL)
					{
						temp->rnext=toins;
						break;
					}
				
					else
					{
						temp=temp->rnext;
					}
				}
			}while(temp!=NULL);
		
		}
	
	
	}

	void print()
	{
		node *temp=new node();
		temp=root;	
		stack<node *> s;
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
				cout<<temp->data;
				temp=temp->rnext;
			}
		}while(temp!=NULL || s.empty()==0);
		cout<<endl;
	}


};







int main()
{
bst b;
b.consbst();
b.print();




return 0;

}
