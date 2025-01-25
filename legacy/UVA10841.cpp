#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
string trash;
vector<int> acc[60];
int T[60];
int adj[110][110];
int dis[110];
int vis[110];
void dijk(int s,int n=99)
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<=n;i++)dis[i]=INT_MAX;
	dis[0]=0;
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	pq.emplace(0,s);
	while(!pq.empty())
	{
		while(!pq.empty()&&vis[pq.top().Y])pq.pop();
		if(pq.empty())break;
		int nx=pq.top().Y;
		int nd=pq.top().X;
		pq.pop();
		vis[nx]=1;
		for(int i=0;i<=n;i++)
		{
			if(adj[nx][i]==INT_MAX)continue;
			int tmp=dis[nx]+adj[nx][i];
			if(nx!=0)tmp+=5;
			if(!vis[i]&&dis[i]>tmp)
			{
				dis[i]=tmp;
				pq.emplace(dis[i],i);
			}
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k)
	{
		
		for(int i=1;i<=n;i++)cin>>T[i];
		getline(cin,trash);
		for(int i=1;i<=n;i++)
		{
			string s;
			getline(cin,s);
			stringstream ss;
			ss<<s;
			int tmp;
			acc[i].clear();
			while(ss>>tmp)acc[i].emplace_back(tmp);
		}
		for(int i=0;i<=99;i++)
			for(int j=0;j<=99;j++)
				adj[i][j]=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<acc[i].size();j++)
				for(int k=0;k<acc[i].size();k++)
				{
					if(j==k)continue;
					int tmp;
					tmp=max(acc[i][j]-acc[i].front(),acc[i].back()-acc[i][j]);
					tmp+=abs(acc[i][j]-acc[i][k]);
					tmp*=T[i];
					adj[acc[i][j]][acc[i][k]]=min(adj[acc[i][j]][acc[i][k]],tmp);
					//cout<<acc[i][j]<<' '<<acc[i][k]<<' '<<adj[acc[i][j]][acc[i][k]]<<endl;
				}
		}
		dijk(0);
		if(dis[k]==INT_MAX)cout<<"IMPOSSIBLE"<<endl;
		else cout<<dis[k]<<endl;
	}
	return 0;
}
/*
10841
10187
10039
721
10243
11374
558
544
*/
