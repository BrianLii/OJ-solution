#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
struct node
{
	int a[12]={0};
};
vector<int> edge[35];
bool ok(const node &a,const node &b,int k)
{
	for(int i=0;i<k;i++)if(a.a[i]<=b.a[i])return 0;
	return 1;
}
int dp[35];
int dfs(int x)
{
	if(dp[x])return dp[x];
	dp[x]=1;
	for(int i:edge[x])
	{
		dp[x]=max(dp[x],dfs(i)+1);
	}
	return dp[x];
}
void trace(int x)
{
	for(int i:edge[x])
	{
		if(dp[i]==dp[x]-1)
		{
			trace(i);
			break;
		}
	}
	cout<<x+1<<' ';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k)
	{
		memset(dp,0,sizeof(dp));
		vector<node> v;
		for(int i=0;i<35;i++)edge[i].clear();
		for(int i=0;i<n;i++)
		{
			v.push_back(node());
			for(int j=0;j<k;j++)cin>>v.back().a[j];
			sort(v.back().a,v.back().a+k);
		}
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				if(ok(v[i],v[j],k))edge[i].push_back(j);
				if(ok(v[j],v[i],k))edge[j].push_back(i);
			}
		for(int i=0;i<n;i++)dfs(i);
		int ans=0,mp=-1;
		for(int i=0;i<n;i++)
		{
			if(dp[i]>ans)
			{
				mp=i;
				ans=dp[i];
			}
		}
		cout<<ans<<endl;
		trace(mp);
		cout<<endl;
	}
	return 0;
}

