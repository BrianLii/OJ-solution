#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int dx[]{ 0, 0, 0, 0, 1,-1};
int dy[]{ 1,-1, 0, 0, 0, 0};
int dz[]{ 0, 0,-1, 1, 0, 0};
struct sta
{
	int x,y,z,d;
	sta(int a,int b,int c,int _d)
	{
		x=a;
		y=b;
		z=c;
		d=_d;
	}
	sta()
	{
		z=y=x=0;
	}
};
string board[40][40];
int sx,sy,sz,ex,ey,ez;
int l,r,c;
int vis[40][40][40];
void bfs()
{
	memset(vis,0,sizeof(vis));
	queue<sta> q;
	q.push(sta(sx,sy,sz,0));
	vis[sx][sy][sz]=1;
	while(!q.empty())
	{
		sta &tmp=q.front();
		q.pop();
		int nx=tmp.x,ny=tmp.y,nz=tmp.z,nd=tmp.d;
		if(nx==ex&&ny==ey&&nz==ez)
		{
			cout<<"Escaped in "<<nd<<" minute(s)."<<endl;
			return;
		}
		for(int i=0;i<6;i++)
		{
			if(nx+dx[i]<l&&nx+dx[i]>=0&&
			   ny+dy[i]<r&&ny+dy[i]>=0&&
			   nz+dz[i]<c&&nz+dz[i]>=0&&
			   !vis[nx+dx[i]][ny+dy[i]][nz+dz[i]]&&
			   board[nx+dx[i]][ny+dy[i]][nz+dz[i]]!='#'
			)
			{
				q.push(sta(nx+dx[i],ny+dy[i],nz+dz[i],nd+1));
				vis[nx+dx[i]][ny+dy[i]][nz+dz[i]]=1;
			}
		}
	}
	cout<<"Trapped!"<<endl;
}
int main() 
{
	
	while(cin>>l>>r>>c)
	{
		if(!l)
		{
			return 0;
		}
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				cin>>board[i][j];
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
					if(board[i][j][k]=='S')
					{
						sx=i;
						sy=j;
						sz=k;	
					}
		
		for(int i=0;i<l;i++)
			for(int j=0;j<r;j++)
				for(int k=0;k<c;k++)
					if(board[i][j][k]=='E')
					{
						ex=i;
						ey=j;
						ez=k;	
					}
		bfs();
	}
	return 0;
}

