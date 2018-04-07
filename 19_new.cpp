#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	//system("color 30");
	//system("color 04");
	cout<<"\t\t\tOrder of Billing\n";
	cout<<"\t\t\t-----------------\n\n";
	int i,j,n;
	system("color 02");
	cout<<"Enter no of Students:";
	cin>>n;
	int a[n],b[n];
	cout<<"\n\n\nEnter no. of gifts student have:\n\n";
	for(i=0;i<n;i++)
	{
		cout<<"S"<<i+1<<": ";
		cin>>a[i];
		b[i]=i+1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				swap(b[j],b[j+1]);
			}
		}
	}
	cout<<"\n\n\nOrder of Billed Students:\n\n";
	for(i=n-1;i>=0;i--)
	{
		cout<<"S"<<b[i]<<": "<<a[i]<<endl;
	}
}
