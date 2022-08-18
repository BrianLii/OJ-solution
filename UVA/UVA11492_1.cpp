#include<bits/stdc++.h>
#define endl '\n'
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
struct E
{
	int t,u,w;
	E(int _t,int _u,int _w)
	{
		t=_t;
		u=_u;
		w=_w;
	}
	E(){}
};
struct cmp
{
	bool operator()(const node a,const node b)const
	{
		return a.dis>b.dis;
	}
};
vector<E>edge[maxn+50];
int dis[maxn+50][27];
int vis[maxn+50][27];
void dijk(int s,int n)
{
	for(int i=0;i<=maxn;i++)
		for(int j=0;j<=26;j++)
			dis[i][j]=INT_MAX;
	memset(vis,0,sizeof(vis));
	priority_queue<node,vector<node>,cmp> pq;
	for(int i=0;i<=26;i++)
	{
		dis[s][i]=0;
	}
	pq.push(node(s,26,0));
	while(pq.size())
	{
		while(pq.size()&&vis[pq.top().a][pq.top().b])pq.pop();
		if(pq.empty())break;
		int na=pq.top().a;
		int nb=pq.top().b;
		vis[na][nb]=1;
		for(auto &i:edge[na])
		{
			if(i.u==nb)continue;
			if(!vis[i.t][i.u]&&dis[i.t][i.u]>dis[na][nb]+i.w)
			{
				dis[i.t][i.u]=dis[na][nb]+i.w;
				pq.push(node(i.t,i.u,dis[i.t][i.u]));
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int S,T;
	int m;
	while(cin>>m)
	{
		if(!m)break;
		mp.clear();
		for(int i=0;i<=maxn;i++)edge[i].clear();
		string l,r,p;
		cin>>l>>r;
		S=conv(l);
		T=conv(r);
		for(int i=0;i<m;i++)
		{
			cin>>l>>r>>p;
			int cl=conv(l),cr=conv(r);
			edge[cl].emplace_back(cr,p[0]-'a',p.size());
			edge[cr].emplace_back(cl,p[0]-'a',p.size());
		}
		dijk(S,mp.size());
		int ans=INT_MAX;
		for(int i=0;i<26;i++)ans=min(ans,dis[T][i]);
		if(ans==INT_MAX)cout<<"impossivel"<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

