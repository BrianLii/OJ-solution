#include<bits/stdc++.h>
using namespace std;
	#define endl '\n'
string board[200];
int vis[200][200];
int dx[]{-1,-1,-1, 0, 0, 1, 1, 1};
int dy[]{ 0, 1,-1, 1,-1, 0, 1,-1};
typedef pair<int,int> pii;
int n,m;
void bfs(int a,int b)
{
	memset(vis,0,sizeof(vis));
	int cnt=0;
	queue<pii> q;
	q.push(pii(a,b));
	vis[a][b]=1;
	cnt++;
	while(!q.empty())
	{
		int nx=q.front().first,ny=q.front().second;
		q.pop();
		for(int i=0;i<8;i++)
		{
			if(nx+dx[i]<n&&nx+dx[i]>=0&&
			   ny+dy[i]<m&&ny+dy[i]>=0&&
			   !vis[nx+dx[i]][ny+dy[i]]&&
			   board[nx+dx[i]][ny+dy[i]]=='W')
			{
				vis[nx+dx[i]][ny+dy[i]]=1;
				
				cnt++;
				q.push(pii(nx+dx[i],ny+dy[i]));
			}
		}
	}
	cout<<cnt<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	string in;
	getline(cin,in);
	getline(cin,in);
	bool flag=0;
	while(t--)
	{
		for(n=0;;n++)
		{
			getline(cin,in);
			if(in[0]=='L'||in[0]=='W')board[n]=in;
			else break;
		}
		m=board[1].size();
		///in have some num
		do
		{
			stringstream ss;
			ss<<in;
			int a,b;
			ss>>a>>b;
			a--;
			b--;
			bfs(a,b);
		}while(getline(cin,in)&&in!="");
		if(t)cout<<endl;
	}
	return 0;
}
/*
2

LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
7 5

LLLLLLLLL
LLWWLLWLL
LWWLLLLLL
LWWWLWWLL
LLLWWWLLL
LLLLLLLLL
LLLWWLLWL
LLWLWLLLL
LLLLLLLLL
3 2
7 5
*/
