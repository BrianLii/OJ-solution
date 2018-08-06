#include<bits/stdc++.h>
using namespace std;
int a[10030];
int s[10030];
pair<int,int> dp[10030];//[n][last one picked]
int main()
{
	int n;
	cin>>n;
	cin>>a[0];
	bool flag1=1;
	bool flag=0;
	if(a[0]<0)
	{
		n--;
		flag1=0;
		flag=1;
	}
	else s[0]=a[0];
	
	for(int i=flag1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0&&!flag)
		{
			i--;
			n--;
			flag=1;
			continue;
		}
		s[i]=s[i-1]+a[i];
	}
	for(int i=0;i<n;i++)cout<<s[i]<<' ';
	cout<<endl;
	if(a[0]<0)dp[0]=make_pair(a[0],0);
	else dp[0]=make_pair(0,10020);
	for(int i=1;i<n;i++)
	{
		int pick=dp[i-1].first+(s[i]-s[dp[i-1].second]);
		int notpick=dp[i-1].first;
		if(pick>notpick)dp[i]=make_pair(pick,i);
		else dp[i]=make_pair(notpick,dp[i-1].second);
	}
	cout<<dp[n-1].first<<endl;
}

