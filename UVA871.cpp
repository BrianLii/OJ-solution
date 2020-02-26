#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
#define X first 
#define Y second
using namespace std;
typedef pair<int,int> pii;
string board[700];
const int dx[]{-1, 0, 1,-1, 1,-1, 0, 1};
const int dy[]{ 1, 1, 1, 0, 0,-1,-1,-1};
bool vis[700][700];
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
		for(int i=0;i<8;i++)
		{
			if(in(nx+dx[i],ny+dy[i])&&board[nx+dx[i]][ny+dy[i]]=='1'&&!vis[nx+dx[i]][ny+dy[i]])
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
	int T;
	cin>>T;
	string tra;
	getline(cin,tra);
	getline(cin,tra);
	while(T--)
	{
		string s;
		n=0,m=0;
		while(getline(cin,s))
		{
			if(s=="")break;	
			board[n++]=s;
		}	
		m=board[0].size();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				vis[i][j]=0;
		int ans=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(!vis[i][j]&&board[i][j]=='1')
					ans=max(ans,bfs(pii(i,j)));
		cout<<ans<<endl;
		if(T)cout<<endl;
	}
	return 0;
}

