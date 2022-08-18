#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
unordered_map<string,int> mp;
typedef pair<int,int> pii;
#define maxn 4500
int conv(string s)
{
	if(mp.find(s)==mp.end())
	{
		mp[s]=mp.size();
		return mp.size();
	}
	else return mp[s];
}
struct node
{
	int a,b,dis;
	node(){}
	node(int _a,int _b,int _dis)
	{
		a=_a;
		b=_b;
		dis=_dis;
	}
};

struct cmp
{
	bool operator()(const node a,const node b)const
	{
		return a.dis>b.dis;
	}
};
vector<pii>edge[maxn+50][26];
int dis[maxn+50][26];
int vis[maxn+50][26];
void dijk(int s,int n)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<26;j++)
			dis[i][j]=INT_MAX;
	memset(vis,0,sizeof(vis));
	priority_queue<node,vector<node>,cmp> pq;
	while(pq.size())
	{
		while(pq.size()&&vis[pq.top().a][pq.top().b])pq.pop();
		if(pq.empty())break;
		int na=pq.top().a;
		int nb=pq.top().b;
		for(auto &i:edge[na][nb])
		{
			if(!vis[i.a][i.b]&&dis[na][nb]+i.second
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int S,T;
	int m;
	cin>>m;
	string l,r,p;
	cin>>l>>r;
	S=conv(l);
	T=conv(r);
	for(int i=0;i<m;i++)
	{
		cin>>l>>r>>p;
		int cl=conv(l),cr=conv(r);
		for(int j=0;j<26;j++)
		{
			edge[cl][j].emplace_back(cr,p.size());
			edge[cr][j].emplace_back(cl,p.size());
		}
	}
	return 0;
}

