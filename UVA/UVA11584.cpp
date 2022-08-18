#include<bits/stdc++.h>
using namespace std;
string s;
bool check(int l,int r)
{
	bool fail=0;
	for(int i=l,j=r;i<j&&!fail;i++,j--)
	{
		if(s[i]!=s[j])fail=1;
	}
	return !fail;
}
int dp[1020][1020];
int use[1020][1020];
int cnt;
int dfs(int l,int r)
{
	if(use[l][r]==cnt)return dp[l][r];
	use[l][r]=cnt;
	if(check(l,r))return dp[l][r]=1;
	dp[l][r]=INT_MAX;
	for(int i=l;i<r;i++)
	{
		dp[l][r]=min(dfs(l,i)+dfs(i+1,r),dp[l][r]);
	}
	return dp[l][r];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cnt++;
		cin>>s;
		cout<<dfs(0,s.size()-1)<<'\n';		
	}

	return 0;
}

