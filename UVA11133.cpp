#include<bits/stdc++.h>
using namespace std;
int a1,an;
int dp[55];
int use[55];
int dfs(int now)
{
	if(now<a1)return 0;
	if(now==a1)return 1;
	if(use[now])return dp[now];
	use[now]=1;
	int sum=0;
	for(int i=now-1;i>=a1;i--)
	{
		if(now%(now-i)==0)
		{
			sum+=dfs(i);
		}
	}
	return dp[now]=sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>a1>>an)
	{
		if(!a1&&!an)return 0;
		cout<<a1<<' '<<an<<' ';
		memset(dp,0,sizeof(dp));
		memset(use,0,sizeof(use));
		cout<<dfs(an)<<endl;
	}
	return 0;
}

