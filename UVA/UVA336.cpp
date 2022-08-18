#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
vector<int>edge[60];
unordered_map<int,int> mp;
int cnt;
int conv(int x)
{
	if(!mp[x])mp[x]=++cnt;
	return mp[x];
}
int vis[60];
int bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	queue<pii> q;
	q.emplace(s,t);
	int ans=1;
	vis[s]=1;
	while(q.size())
	{
		int now=q.front().first;
		int nt=q.front().second;
		q.pop();
		if(!nt)continue;
		for(int i:edge[now])
		{
			if(!vis[i])
			{
				vis[i]=1;
				ans++;
				q.emplace(i,nt-1);
			}
		}
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int ccnt=0;
	while(cin>>n)
	{
		if(!n)break;
		mp.clear();
		for(int i=0;i<40;i++)edge[i].clear();
		cnt=0;
		for(int i=0;i<n;i++)
		{
			int ta,tb;
			cin>>ta>>tb;
			ta=conv(ta);
			tb=conv(tb);
			edge[ta].push_back(tb);
			edge[tb].push_back(ta);
		}
		int s,T;
		while(cin>>s>>T)
		{
			if(!s&&!T)break;
			int ans=bfs(conv(s),T);
			cout<<"Case "<<++ccnt<<": ";
			cout<<cnt-ans<<" nodes not reachable from node ";
			cout<<s<<" with TTL = "<<T<<'.'<<endl;
		}
	}
	return 0;
}

