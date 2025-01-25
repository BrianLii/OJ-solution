#include<bits/stdc++.h>
using namespace std;
int mii[9]{1,10,100,1000,10000,100000,
			1000000,10000000,100000000};
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<mii[n];i++)
		{
			if((i/mii[n/2]+i%mii[n/2])*(i/mii[n/2]+i%mii[n/2])==i)
			{
				int now=i;
				for(int j=n-1;j>=0;j--)
				{
					cout<<now/mii[j];
					now%=mii[j];
				}
				cout<<endl;
			}
		}
	}
	return 0;
}

