#include<bits/stdc++.h>
using namespace std;
int a[120];
int sta[120];
bool isG(int x)
{
	return (sta[x]%(a[x]*2)<a[x]-5);	
}
void out(int x)
{
	printf("%02d:",x/3600);
	printf("%02d:",(x%3600)/60);
	printf("%02d\n",x%60);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int outcount=0;
	while(1)
	{
		int n=-1;
		int ma=0;
		while(cin>>a[++n])
		{
			if(a[n]==0)break;
			else ma=max(ma,a[n]); 
		}
		if(n==0)
		{
			outcount++;	
		}
		else outcount=0;
		if(outcount==3)
		{
			break;
		}
		if(n==0)continue;
		int now=0;
		bool suss=0;
		while(now<=18000)
		{
			if(now<=ma-4)
			{
				for(int i=0;i<n;i++)
				{
					sta[i]++;
				}
				now++;
				continue;	
			}
			bool fail=0;
			for(int i=0;i<n&&!fail;i++)
			{
				if(!isG(i))fail=1;
			}
			if(!fail)
			{
				out(now);
				suss=1;
				break;
			}
			for(int i=0;i<n;i++)
			{
				sta[i]++;
			}
			now++;
		}
		if(!suss)cout<<"Signals fail to synchronise in 5 hours"<<endl;
	}
	return 0;
}

