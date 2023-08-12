#include<iostream>
#include<stack>
using namespace std;

class node
{
public:
int data;
node *rnext;
node*lnext;
int height;
	
	node()
	{
		this->rnext=NULL;
		this->lnext=NULL;
		this->data=0;
		this->height=1;
	}
	
	node(int data)
	{
		this->rnext=NULL;
		this->lnext=NULL;
		this->data=data;
		this->height=1;
	}
};

class avl:public node
{
public:
	
	node *root=new node();
	

	int height(node *temp)
	{
		int hr,hl;
		
		if(temp==NULL)
		{
			return 0;
		}
		
		if(temp->lnext==NULL && temp->rnext==NULL)
		{
			return 1;
		}
		
		else
		{
			hl=height(temp->lnext);
			hr=height(temp->rnext);
			
			if(hr>hl)
			{
				return hr+1;
			}
			
			else
			{
				return hl+1;
			}
		}
	cout<<hl<<" "<<hr<<" "<<hl-hr;
	}

	int BF(node *temp)
	{
		int hl,hr;
		hl=height(temp->lnext);
		hr=height(temp->rnext);
		
		return hl-hr;
	
	}	
	
	node *ll(node *A)
	{
		node *B=A->lnext;
		A->lnext=B->rnext;
		B->rnext=A;
		
		
		
		return B;
	}
	
		
	node *rr(node *A)
	{
		node *B=A->rnext;
		A->rnext=B->lnext;
		B->lnext=A;
		
		return B;
	} 
	
	node *lr(node *A)
	{
		node *B=A->lnext;
		node *C=B->rnext;
		
		B->rnext=C->lnext;
		A->lnext=C->rnext;
		
		C->lnext=B;
		C->rnext=A;
		
		return C;
	}
	
	node *rl(node *A)
	{
		node *B=A->lnext;
		node *C=B->rnext;
		
		A->rnext=C->lnext;
		B->lnext=C->rnext;
		
		C->lnext=A;
		C->rnext=B;
		
		return C;
	}
	
	
	void insert(int data)
	{
	
		node *toins=new node(data);
		int bf;
		stack<node *> s1;
		if(root->data==0)
		{
			root->data=toins->data;
			cout<<"Root created."<<endl;
		}
		
		else
		{
			node *temp=new node();
			temp=root;
			
			do
			{
				if(toins->data<temp->data)
				{
					if(temp->lnext==NULL)
					{
						temp->lnext=toins;
						cout<<toins->data<<" added at left of "<<temp->data<<"."<<endl;
						break;
					}
				
					else
					{
						s1.push(temp);
						temp=temp->lnext;				
					}
				}
				
				if(toins->data>temp->data)
				{
					if(temp->rnext==NULL)
					{
						temp->rnext=toins;
						cout<<toins->data<<" added at right of "<<temp->data<<"."<<endl;
						break;
					}
				
					else
					{
						s1.push(temp);				
						temp=temp->rnext;
					}
				}		
			}while(temp!=NULL);
		}
		
		
			//root->height = call_height(root);
			if(BF(root)==2 && BF(root->lnext)==1){
				root=ll(root);
			}
			if(BF(root)==2 && BF(root->lnext)==-1){
				root=lr(root);
			}
			if(BF(root)==-2 && BF(root->rnext)==-1){
				root=rr(root);
			}
			if(BF(root)==-2 && BF(root->rnext)==1){
				root=rl(root);
			}
			
	}
/*
	void remove()
	{
	
	
	
	}
*/
	
	void inorder()
	{
		node *temp=root;
		stack<node *> s2;
		do
		{
			while(temp!=NULL)
			{
				s2.push(temp);
				temp=temp->lnext;
			}
		
			if(temp==NULL)
			{
				temp=s2.top();
				s2.pop();
				cout<<temp->data<<" ";
				temp=temp->rnext; 		
			}
		}while(temp!=NULL || s2.empty()==0);
		cout<<endl;	
	}

	
};



int main()
{
avl a;

a.insert(5);
a.insert(6);
a.insert(7);
a.insert(11);
a.insert(13);

a.insert(15);
a.insert(16);
a.insert(14);
a.insert(8);
a.insert(9);
a.insert(10);

a.inorder();




return 0;
}
