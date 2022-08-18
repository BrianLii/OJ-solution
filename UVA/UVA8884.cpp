#include<bits/stdc++.h>
using namespace std;
int np[1000020];
int fac_num[1000020];
int sum[1000020];
void sai(int x=1000000)
{
	int i;
	for(int i=2;i*i<=x;i++)
	{
		if(!np[i])
		{
			np[i]=i;
			for(int j=i*i;j<=x;j+=i)
				if(!np[j])np[j]=i;
		}
	}
	for(;i<=x;i++)
	{
		if(!np[i])np[i]=i;
	}
}
void fan(int x)
{
	int now=x;
	while(now>1)
	{
		int tmp=np[now];
		while(now%tmp==0)
		{
			now/=tmp;
			fac_num[x]++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sai();
	for(int i=2;i<=1000000;i++)
		fan(i);
	for(int i=2;i<=1000000;i++)
	{
		sum[i]=fac_num[i]+sum[i-1];
	}
	int n;
	while(cin>>n)
	{
		cout<<sum[n]<<endl;
	}
	return 0;
}

