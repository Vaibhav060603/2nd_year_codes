#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

class graph
{
public: 
int nedge;
int nvertex=5;
int i,j;
char adjmat[6][6]; 
	
	
	void vnamein()
	{	
	        char vname;
		
		adjmat[0][0]='/';
		
		for(i=1;i<=nvertex;i++)
		{
			cout<<"Enter the name of vertex "<<i<<": ";
			cin>>vname;
			adjmat[0][i]=vname;
			adjmat[i][0]=vname;
		}
	}
	
	

	void crgraph()
	{
	
		for(i=1;i<=nvertex;i++)
		{
			for(j=1;j<=nvertex;j++)
			{
				adjmat[i][j]='0';
			}	
		}
		
			
	 	int x,y;
	 
		cout<<"How many edges are present in graph :";
		cin>>nedge;
		
		for(i=0;i<nedge;i++)
		{
			cout<<"Enter the vertices between which an edge is present (by giving a space between them) :";
			cin>>x>>y;
			
				if(x>0 && y>0 && x<=nedge && y<=nedge)
				{
					adjmat[x][y]='1';		
				}
				
				else
				{
					cout<<"Enter the correct details.";
					crgraph();
				}
				
		}
		
	}
	
	void print()
	{
		cout<<"The adjacency is matrix :"<<endl;
		for(i=0;i<=nvertex;i++)
		{
			for(j=0;j<=nvertex;j++)
			{
				cout<<adjmat[i][j]<<" ";	
			}
			cout<<endl;
		}
	
	}

        void DFS()
        {
        	
        
        }


	void BFS(int start)
	{
		int i;
		int temp;
		queue<int> q;
		int visited[nvertex+1]={0};
		
		q.push(start);
	        cout<<adjmat[0][start];
	        visited[start]=1;
		
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			for(i=1;i<nvertex;i++)
			{
				if(adjmat[temp][i]=='1' && visited[i]==0)
				{
					cout<<adjmat[0][i]<<" ";
					q.push(i);
					visited[i]=1;
				}
			}
		}
		cout<<endl;
	}
	
};


int main()
{

graph g;
g.vnamein();
g.crgraph();
g.print();
g.BFS(1);


return 0;
}
