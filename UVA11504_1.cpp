#include<bits/stdc++.h>
using namespace std;
int vis[100100];
vector<int> edge[100100],nedge[100100],topo;
int scc[100100],in[100100],n;
void dfs1(int now)
{
	vis[now]=1;
	for(int i:edge[now])
		if(!vis[i])dfs1(i);
	topo.push_back(now);
}
void dfs2(int now,int tag)
{
	scc[now]=tag;
	vis[now]=1;
	for(int i:nedge[now])
		if(!vis[i])dfs2(i,tag);
}
int ksrju()
{
	topo.clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs1(i);
	memset(vis,0,sizeof(vis));
	int num=0;
	for(int i=n-1;i>=0;i--)
		if(!vis[topo[i]])
			dfs2(topo[i],++num);
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
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			edge[i].clear();
			nedge[i].clear();
			scc[i]=0;
			in[i]=0;
		}
		int m;
		cin>>m;
		typedef pair<int,int> pii;
		vector<pii> all;
		for(int i=0,a,b;i<m;i++)
		{
			cin>>a>>b;
			all.push_back(pii(a,b));
			edge[a].push_back(b);
			nedge[b].push_back(a);
		}
		int len=ksrju();
		for(auto i:all)
			if(scc[i.first]!=scc[i.second])
				in[scc[i.second]]++;
		int ans=0;
		for(int i=1;i<=len;i++)
			if(in[i]==0)ans++;
		cout<<ans<<endl;
	}
	return 0;
}

