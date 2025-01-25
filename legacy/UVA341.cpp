#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>edge[100];
int vis[100];
int dis[100];
int fa[100]; 
struct cmp
{
	bool operator()(int _a,int _b)
	{
		return dis[_a]>dis[_b];
	}
};
void rec(int x)
{
	if(!x)return;
	rec(fa[x]);
	cout<<' '<<x;
}
int dijkstra(int s,int e)
{
	priority_queue<int,vector<int>,cmp>pq; 
	dis[s]=0;
	pq.push(s);
	while(!pq.empty())
	{
		int now=pq.top();
		pq.pop();
		if(now==e)return dis[e];
		if(!vis[now])
		{
			vis[now]=1;
			for(auto i:edge[now])
			{
				if(!vis[i.first]&&dis[i.first]>dis[now]+i.second)
				{
					dis[i.first]=dis[now]+i.second;
					fa[i.first]=now;
					pq.push(i.first);
				}		
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt=0;
	while(cin>>n)
	{
		if(!n)return 0;
		for(int i=0;i<=n;i++)
		{
			edge[i].clear();
			dis[i]=1e9;
			vis[i]=0;
			fa[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			int m;
			cin>>m;
			for(int j=0;j<m;j++)
			{
				int to,w;
				cin>>to>>w;
				edge[i].emplace_back(pii(to,w));
			}
		}
		int s,e;
		cin>>s>>e;
		int len= dijkstra(s,e);
		cout<<"Case "<<++cnt<<": Path =";
		rec(e);
		cout<<"; "<<len<<" second delay"<<endl;
	}
	return 0;
}

