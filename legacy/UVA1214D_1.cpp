#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
#define X first 
#define Y second
using namespace std;
typedef pair<int,int> pii;
string board[1000000];
const int dx[]{ 1, 0};
const int dy[]{ 0, 1};
vector<vector<bool> > vis;
int n,m;
bool in(int x,int y)
{
	return 0<=x&&x<n&&0<=y&&y<m;
}
int bfs(pii start)
{
	queue<pii>q;
	q.emplace(start);
	int cnt=0;
	while(q.size())
	{
		int nx=q.front().X,ny=q.front().Y;
		q.pop();
		if(vis[nx][ny])continue;
		vis[nx][ny]=1;
		cnt++;
		for(int i=0;i<2;i++)
		{
			if(in(nx+dx[i],ny+dy[i])&&board[nx+dx[i]][ny+dy[i]]=='.'&&!vis[nx+dx[i]][ny+dy[i]])
			{
				q.emplace(nx+dx[i],ny+dy[i]);
			}
		}
	} 
	return cnt;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	vis.resize(n);
	for(int i=0;i<n;i++)vis[i].resize(m);
	for(int i=0;i<n;i++)cin>>board[i];
	return 0;
}

