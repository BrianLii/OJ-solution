#include<bits/stdc++.h>
#define clear(x) memset(x,0,sizeof(x))
using namespace std;
int to[50020];
int vis[50020];
int num[50020];
int dfs2(int,int,int);
//find loop
int dfs(int x)
{
	//cout<<x<<endl;
	if(vis[x]&&!num[x])
	{
		num[x]=dfs2(to[x],1,x);
		return num[x];	
	}
	vis[x]=1;
	if(num[x])return num[x];
	int tmp=dfs(to[x]);
	if(num[x])return num[x];
	else return num[x]=tmp+1;
}
int dfs2(int x,int cnt,int ed)
{
	if(x==ed)return cnt;
	return num[x]=dfs2(to[x],cnt+1,ed);
}
////////////
int dp[50020];
int use[50020];
int dfs3(int x)
{

	if(use[x])return dp[x];
	use[x]=1;
	if(num[x])return num[x];
	else return dp[x]=dfs3(to[x])+1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#define endl '\n'
	int t;
	cin>>t;
	int ct=0;
	while(t--)
	{
		clear(dp);
		clear(use);
		clear(to);
		clear(vis);
		clear(num);
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			to[u]=v;
		}
		///build
		for(int i=1;i<=n;i++)
		{
			if(vis[i])continue;
			dfs(i);
		}
		/////////
		int ma=1,manum=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			int tmp=dfs3(i);
			if(tmp>ma)
			{
				ma=tmp;
				manum=i;
			}
		}
		cout<<"Case "<<++ct<<": ";
		cout<<manum<<endl;
	}

	return 0;
}

/*
1
5
1 2
2 3
3 4
4 5
5 4
*/
