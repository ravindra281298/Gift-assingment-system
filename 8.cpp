#include<bits\stdc++.h>
#include<windows.h>
using namespace std;

int waitingtime(int n,int bt[],int wt[],int q)
{
	int re[n],i,t=0;
	for(i=0;i<n;i++)
	re[n]=bt[i];
	while(true)
	{
		bool d=true;
		for(i=0;i<n;i++)
		{
			if(re[i]>0)
			{
				d=false;
				if(re[i]>q)
				{
				   t+=q;
				   re[i]-=q;
			    }
			    else
			    {
			    	t+=re[i];
			    	wt[i]=t-bt[i];
			    	re[i]=0;
				}
			}
		}
		if(d==true)
		break;
	}
	
} 

void turnaroundtime(int n,int bt[],int wt[],int tt[])
{
	for(int i=0;i<n;i++)
	tt[i]=bt[i]+wt[i];
}

int main()
{
	system("color 30");
	int i,j,n,q,avgw=0,avgt=0;
	cout<<"Enter no. of processes: ";
	cin>>n;
	cout<<"Enter time quantum: ";
	cin>>q;
	int at[n],wt[n],tt[n],bt[n],pri[n];
	for(i=0;i<n;i++)
	{
		cout<<"\n\n\n";
		cout<<"Process P"<<i+1<<endl;
		cout<<"Enter arrival time: ";
		cin>>at[i];
		cout<<"Enter Burst time: ";
		cin>>bt[i];
		cout<<"Enter priority: ";
		cin>>pri[i];
	}
	
	for(i=0;i<n;i++)
	{
      wt[i]=0;
      tt[i]=0;
    }
	//for(i=0;i<n;i++)
	waitingtime(n,bt,wt,q);
	turnaroundtime(n,bt,wt,tt);
	
	for(i=0;i<n;i++)
	{
		//cout<<wt[i]<<" "<<tt[i];
		avgw+=wt[i];
		avgt+=tt[i];
	}
	
	
	cout<<"\n\nProcess\tArrival time\tPriority\tBurst time\tWaiting time\tTurnaround time\n"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"P"<<i+1<<"\t"<<at[i]<<"\t\t"<<pri[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<endl;
	}
	printf("Average waiting time: %f\n",(float)avgw/(float)n);
	printf("Average Turnaround time: %f\n",(float)avgt/(float)n);  
}
