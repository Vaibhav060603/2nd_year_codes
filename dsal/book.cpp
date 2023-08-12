#include<iostream>
#include<string>
#include<stack>
using namespace std;

class node
{
public:
string s;
node *lnext;
node *rnext;

	node()
	{
		this->s="/";
		this->lnext=NULL;
		this->rnext=NULL;
	}
	
	node(string s)
	{
		this->s=s;
		this->lnext=NULL;
		this->rnext=NULL;
	}
};

class book:public node
{
public:
node *title=new node();

	void inserttit(string tit)
	{
		if(title->s=="/")
		{
			title->s=tit;
			cout<<"Title created."<<endl;
			
		}
	
		else
		{
			cout<<"Title already exist."<<endl;		
		}
	}
	
	void insertch(string ch)
	{
		node *toins=new node(ch);
		
		if(title->s=="/")
		{
			cout<<"First give the title of book."<<endl;
		}
		
		else if(title->lnext==NULL)
		{
			title->lnext=toins;
			cout<<"Chapter 1 created."<<endl;
			
		}
		
		else
		{
			node *temp=title->lnext;
			
			if(temp->s==ch)
			{
				cout<<ch<<" already exist."<<endl;
			}
			
			else
			{		
			while(temp!=NULL)
			{
				if(temp->rnext==NULL)
				{
					temp->rnext=toins;
					cout<<ch<<" created."<<endl;
					break;
				}
		
				else
				{
					temp=temp->rnext;
					if(temp->s==ch)
					{
						cout<<ch<<" already exist."<<endl;
						break;
					}
				}
			}
			}
		}
	}
	
	void insertsec(string ch,string sec)
	{
		node *toins=new node(sec);
		
		if(title->s=="/")
		{
			cout<<"First give the title of book."<<endl;
		}
		
		else if(title->lnext==NULL)
		{
			cout<<"First make the chapter of book."<<endl;
		}
		
		else
		{
			node *temp=title->lnext;
			
			while(temp!=NULL)
			{
				if(temp->s==ch)
				{	
				
					if(temp->lnext==NULL)
					{
						temp->lnext=toins;
						cout<<"First section created in "<<ch<<"."<<endl;
						break;
					}
				
					else
					{
						temp=temp->lnext;
						
						if(temp->s==sec)
						{
							cout<<sec<<" already exist."<<endl;
							break;
						}
						
						while(temp!=NULL)
						{
							if(temp->rnext==NULL)
							{
								temp->rnext==toins;
								cout<<sec<<" created in "<<ch<<"."<<endl;
								break;
							}
						
							else
							{
								temp=temp->rnext;
								if(temp->s==sec)
								{
									cout<<sec<<" already exist."<<endl;
									break;
								}
							}
						}
					 }
				}
			
				if(temp->s!=ch)
				{
					
					if(temp->rnext==NULL)
					{
						cout<<"Chapter does not exist."<<endl;
					}
					temp=temp->rnext;
				}
			}
		}
	}
	
	void preorder()
	{
		node *temp=title;
		stack<node *> s;
		cout<<endl;
		
		do
		{
			while(temp!=NULL)
			{
				s.push(temp);
				cout<<temp->s<<endl;
				temp=temp->lnext;
			}
		
			if(temp==NULL)
			{
				temp=s.top();
				s.pop();
				temp=temp->rnext;
			}
		}while(temp!=NULL || s.empty()==0);
		cout<<endl;
	}


};

int main()
{
book b;
b.inserttit("Book");
b.insertch("chapter 1");
b.insertsec("chapter 1","section 1");
b.insertch("chapter 1");
b.insertch("chapter 2");
b.insertsec("chapter 1","section 1");
b.insertsec("chapter 2","section 1");
b.preorder();


return 0;
}
