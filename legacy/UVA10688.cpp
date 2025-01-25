#include<bits/stdc++.h>
//#define endl '\n'
using namespace std;
int n,k;
int cnt;
int dp[600][600],use[600][600];
int dfs(int l,int r)
{
	if(l==r)return dp[l][r]=0;
	if(use[l][r]==cnt)return dp[l][r];
	use[l][r]=cnt;
	int mi=INT_MAX;
	for(int i=l;i<=r;i++)
	{
		int ans=0;
		if(i!=l)ans+=dfs(l,i-1);
		if(i!=r)ans+=dfs(i+1,r);
		ans+=(i+k)*(r-l+1);
		mi=min(mi,ans);
	}
	return dp[l][r]=mi;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cout<<"Case "<<++cnt<<": ";
		cin>>n>>k;
		//cout<<n<<' '<<k<<endl;
		cout<<dfs(1,n)<<endl;
	}
	return 0;
}

