#include<bits/stdc++.h>
using namespace std;
int a[60];
int len;
int n;
int dp[80][80];
int dfs(int l,int r)
{
	if(l+1==r)return 0;
	if(dp[l][r])return dp[l][r];
	dp[l][r]=INT_MAX;
	for(int i=l+1;i<r;i++)
	{
		dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i,r)+a[r]-a[l]);
	}
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>len)
	{
		if(!len)return 0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		a[0]=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		a[n+1]=len;
		cout<<"The minimum cutting is ";
		cout<<dfs(0,n+1)<<".\n"; 
	}
	return 0;
}

