#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int t[10];
vector<int> to[10];
vector<pii> edge[10][120];
vector<int> avl[120];
int dis[10][120];
int vis[10][120];
void out(priority_queue<pii,vector<pii>,greater<pii> > q)
{
	while(q.size())
	{
		cout<<'('<<q.top().first<<' '<<q.top().second<<") ";
		q.pop();
	}
	cout<<endl;
}
int dijkstra(int n,int k)
{
	memset(dis,0x3f,sizeof dis);
	priority_queue<pii,vector<pii>,greater<pii> > q;
	for(int i:avl[0])
	{
		dis[i][0]=0;
		q.push(pii(i,0));
	}
	while(!q.empty())
	{
		while(!q.empty()&&vis[q.top().first][q.top().second])
		{
			q.pop();	
		}
		if(q.empty())break;
		//x=elevator
		//y=floor
		int nx=q.top().first;
		int ny=q.top().second;
		cout<<nx<<' '<<ny<<endl;
		q.pop();
		vis[nx][ny]=1;
		for(auto i:edge[nx][ny])
		{
			if(!vis[nx][i.first]&&dis[nx][i.first]>dis[nx][ny]+i.second)
			{
				dis[nx][i.first]=dis[nx][ny]+i.second;
				q.push(pii(nx,i.first));
			}
		}
		for(int i:avl[ny])
		{
			if(!vis[i][ny]&&dis[i][ny]>dis[nx][ny]+60)
			{
				dis[i][ny]=dis[nx][ny]+60;
				q.push(pii(i,ny));
			}
		}
	}
	int mi=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		mi=min(mi,dis[i][k]);
	}
	return mi;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>t[i];
	string trash;
	getline(cin,trash);
	for(int i=1;i<=n;i++)
	{
		string inp;
		getline(cin,inp);
		stringstream ss;
		ss<<inp;
		int tmp;
		while(ss>>tmp)
		{
			to[i].push_back(tmp);
			avl[tmp].push_back(i);	
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<(int)to[i].size();j++)
		{
			int a,b,w;
			a=to[i][j-1];
			b=to[i][j];
			w=(to[i][j]-to[i][j-1])*t[i];
			edge[i][a].emplace_back(b,w);
			edge[i][b].emplace_back(a,w);
		}
	}
	cout<<dijkstra(n,k)<<endl;
	return 0;
}

