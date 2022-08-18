#include<bits/stdc++.h>
#define int long long
//#define endl '\n'
#define int long long
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
unordered_map<string,int> mp;
int conv(string s)
{
	if(mp.count(s)==0)
	{
		int tmp=mp.size();
		mp[s]=tmp;
		return mp[s];
	}
	else return mp[s];
}
struct E
{
	int t=0,w=0,s=0;
	E(int a,int b,int c)
	{
		t=a;
		w=b;
		s=c;
	}
};
struct node
{
	int d=0,X=0,Y=0;
	node(int _d,int _X,int _Y)
	{
		d=_d;
		X=_X;
		Y=_Y;
	}
};
struct cmp
{
	bool operator()(const node &a,const node &b)
	{
		return a.d>b.d;
	}
};
vector<E>edge[120];
int dis[120][24];
int vis[120][24];
void dijk(int s,int x,int n=110)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=23;j++)
			dis[i][j]=INT_MAX;
	memset(vis,0,sizeof(vis));
	dis[s][x]=0;
	priority_queue<node,vector<node>,cmp> pq;
	pq.emplace(0,s,x);
	while(!pq.empty())
	{
		while(!pq.empty()&&vis[pq.top().X][pq.top().Y])pq.pop();
		if(pq.empty())break;
		node now=pq.top();
		vis[now.X][now.Y]=1;
		pq.pop();
		//cout<<now.X<<' '<<now.Y<<' '<<now.d<<' '<<dis[now.X][now.Y]<<endl;
		for(E i:edge[now.X])
		{
			int flag=0;
			if(now.Y<i.s)
			{
				flag=0;
				if(i.s>=18&&now.Y<=6)flag=1;
			}
			else if(now.Y>i.s)
			{
				flag=1;
				if(now.Y>=18&&i.s<=6)flag=0;
			}
			else flag=0;
			if(!vis[i.t][(i.s+i.w)%24]&&dis[i.t][(i.s+i.w)%24]>dis[now.X][now.Y]+flag)
			{
				dis[i.t][(i.s+i.w)%24]=dis[now.X][now.Y]+flag;
				pq.emplace(dis[i.t][(i.s+i.w)%24],i.t,(i.s+i.w)%24);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int ii=0;ii<T;ii++)
	{
		int m;
		cin>>m;
		for(int i=0;i<110;i++)edge[i].clear();
		mp.clear();
		while(m--)
		{
			string l,r;
			int ta,tb,a,b;
			cin>>l>>r>>a>>b;
			ta=conv(l);
			tb=conv(r);
			if(a<=6)a+=24;
			if(a>=18&&a+b<=30)edge[ta].emplace_back(tb,b,a%24);
		}
		string s,t;
		cin>>s>>t;
		dijk(conv(s),18);
		int ans=INT_MAX;
		for(int i=0;i<24;i++)ans=min(ans,dis[conv(t)][i]);
		cout<<"Test Case "<<ii+1<<'.'<<endl;
		if(ans==INT_MAX)cout<<"There is no route Vladimir can take."<<endl;
		else cout<<"Vladimir needs "<<ans<<" litre(s) of blood."<<endl;
	} 
	return 0;
}
/*
1
2
a b 18 1
a b 6 2
a b
*/
