#include<iostream>
using namespace std;

class heap
{
public:
	
	int heapsize=0;
	int hdata[100];
	
	void reheapup(int childindex)
	{
		int temp;
		//int parentindex;
		
		while(hdata[childindex]<hdata[childindex/2])
		{
			temp=hdata[childindex];
			hdata[childindex]=hdata[childindex/2];
			hdata[childindex/2]=temp;
			
			childindex=childindex/2;
				
			if(childindex==0)
			{
				break;
			}
				
		}
	}
	
	void insert(int child)
	{
		heapsize+=1;
		hdata[heapsize]=child;
		int childindex=heapsize;
		reheapup(childindex);
		hdata[0]=heapsize;
	}

	void display()
	{
		int i;
		cout<<"Total number of entries in min. heap :"<<hdata[0]<<endl;
		/*for(i=1;i<=heapsize;i++)
		{
			cout<<hdata[i]<<" ";
		}
		cout<<endl;
		*/
		
		cout<<"Minimum element from the entries :"<<hdata[1]<<endl;		
	}
	
	

};

int main()
{
heap h;
h.insert(7);
h.insert(10);
h.insert(5);
h.insert(6);
h.insert(12);
h.insert(14);
h.insert(9);
h.insert(11);
h.insert(4);


h.display();


return 0;
}
