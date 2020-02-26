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
int dp[1100];
int use[1100];
int cnt;
int dfs(int l)
{
	if(use[l]==cnt)return dp[l];
	use[l]=cnt;
	if(check(0,l))return dp[l]=1;
	dp[l]=INT_MAX;
	for(int i=0;i<l;i++)
	{
		if(check(i+1,l))
			dp[l]=min(dfs(i)+1,dp[l]);	
	} 
	return dp[l];
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
		cout<<dfs(s.size()-1)<<endl;		
	}

	return 0;
}

