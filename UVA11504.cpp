#include<bits/stdc++.h>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
vector<int> edge[100020],nedge[100020];
int vis[100020],vis2[100020];
int scc[100020];
int in[100020];
vector<int> topo;
int n;
void dfs(int now)
{
	vis[now]=1;
	for(int i:edge[now])
	{
		if(!vis[i])dfs(i);
	}
	topo.push_back(now);
}
void dfs2(int now,int tag)
{
	scc[now]=tag;
	vis2[now]=1;
	for(int i:nedge[now])
	{
		if(!vis2[i])dfs2(i,tag);
	}
}
int kousaraju()
{
	for(int i=0;i<n;i++)
	{
		if(!vis[i])dfs(i);
	}
	int num=0;
	for(int i=n-1;i>=0;i--)
	{
		if(!vis2[i])
		{
			dfs2(i,++num);
		}
	}
	return num;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>n>>m;
		CLR(vis);
		CLR(vis2);
		CLR(in);
		CLR(scc);
		topo.clear();
		for(int i=0;i<=n;i++)
		{
			edge[i].clear();
			nedge[i].clear();
		}
		
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			edge[a].push_back(b);
			nedge[b].push_back(a);
		}
		int len=kousaraju();
		for(int i=0;i<n;i++)
		{
			for(int j:edge[i])
			{
				if(scc[i]!=scc[j])
				{
					in[scc[j]]++;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=len;i++)
		{
			cout<<in[i]<<' ';
		}
		cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
/*
5 5 2
0 3
0 1
1 4
1 2
4 2
4 3
4 1
*/
