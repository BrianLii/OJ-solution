#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt;
int used[60][60];
long long dp[60][60];
long long dfs(int now,int num)
{
	if(now==0)
	{
		if(num==0)return 1;
		else return 0;
	}
	if(num<=0)return 0;
	if(used[now][num]==cnt)return dp[now][num];
	used[now][num]=cnt;
	long long sum=0;
	for(int i=1;i<=min(m,now);i++)
	{
		sum+=dfs(now-i,num-1);
	}
	return dp[now][num]=sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>k>>m)
	{
		cnt++;
		long long ans=dfs(n,k);
		cout<<ans<<endl;
	}
	return 0;
}

