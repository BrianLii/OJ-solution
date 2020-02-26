#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pii;
long long t[10];
vector<long long> to[10];
vector<pii> edge[10][120];
vector<long long> avl[120];
long long dis[10][120];
long long vis[10][120];
struct node
{
	long long x,y,d;
	node(long long _x,long long _y,long long _d)
	{
		x=_x;
		y=_y;
		d=_d;
	}
};
bool operator <(const node x,const node y) 
{
	return x.d>y.d;
} 
long long dijkstra(long long n,long long k)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<102;j++)
		{
			dis[i][j]=INT_MAX;
		}
	}
	priority_queue<node> q;
	for(long long i:avl[0])
	{
		dis[i][0]=0;
		q.push(node(i,0,0));
	}
	while(!q.empty())
	{
		while(!q.empty()&&vis[q.top().x][q.top().y])
		{
			q.pop();	
		}
		if(q.empty())break;
		//x=elevator
		//y=floor
		long long nx=q.top().x;
		long long ny=q.top().y;
		if(ny==k)return dis[nx][ny];
		q.pop();
		vis[nx][ny]=1;
		for(auto i:edge[nx][ny])
		{
			if(!vis[nx][i.first]&&dis[nx][i.first]>dis[nx][ny]+i.second)
			{
				dis[nx][i.first]=dis[nx][ny]+i.second;
				q.push(node(nx,i.first,dis[nx][i.first]));
			}
		}
		for(long long i:avl[ny])
		{
			if(!vis[i][ny]&&dis[i][ny]>dis[nx][ny]+60)
			{
				dis[i][ny]=dis[nx][ny]+60;
				q.push(node(i,ny,dis[i][ny]));
			}
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,k;
	while(cin>>n>>k)
	{
		for(long long i=1;i<=n;i++)
		{
			to[i].clear();
			for(long long j=0;j<102;j++)
			{
				edge[i][j].clear();			
			}	
		}
		for(long long i=0;i<102;i++)avl[i].clear();
		for(long long i=1;i<=n;i++)cin>>t[i];
		string trash;
		getline(cin,trash);
		for(long long i=1;i<=n;i++)
		{
			string inp;
			getline(cin,inp);
			stringstream ss;
			ss<<inp;
			long long tmp;
			while(ss>>tmp)
			{
				to[i].push_back(tmp);
				avl[tmp].push_back(i);	
			}
		}
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<(long long)to[i].size();j++)
			{
				long long a,b,w;
				a=to[i][j-1];
				b=to[i][j];
				w=(to[i][j]-to[i][j-1])*t[i];
				edge[i][a].emplace_back(b,w);
				edge[i][b].emplace_back(a,w);
			}
		}
		long long tmp=dijkstra(n,k);
		if(tmp==-1)cout<<"IMPOSSIBLE"<<endl;
		else cout<<tmp<<endl;
	}
	return 0;
}
/*
2 30
10 5
0 1 3 5 7 9 11 13 15 20 99
4 13 15 19 20 25 30
2 30
10 1
0 5 10 12 14 20 25 30
2 4 6 8 10 12 14 22 25 28 29
3 50
10 50 100
0 10 30 40
0 20 30
0 20 50
1 1
2
0 2 4 6 8 10
*/
