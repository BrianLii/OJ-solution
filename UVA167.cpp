#include<bits/stdc++.h>
using namespace std;
int board[10][10];
int use[10][10];
inline void tag(int x,int y,int c)
{
	//cout<<x<<y<<endl;
	int tx=x,ty=y,dx=-1,dy=-1;
	while(tx>=0&&ty>=0)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=1,dy=-1;
	while(tx<8&&ty>=0)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=-1,dy=1;
	while(tx>=0&&ty<8)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=1,dy=1;
	while(tx<8&&ty<8)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	
	tx=x,ty=y,dx=-1,dy=0;
	while(tx>=0&&ty<8)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=0,dy=-1;
	while(tx<8&&ty>=0)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=0,dy=1;
	while(tx<8&&ty<8)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
	tx=x,ty=y,dx=1,dy=0;
	while(tx<8&&ty<8)
	{
		use[tx][ty]-=c;tx+=dx;ty+=dy;
	}
}
int cnt;
int dfs(int x)
{
	if(x==8)
	{
		cnt++;return 0;	
	}
	int ma=0;
	for(int i=0;i<8;i++)
	{
		if(!use[x][i])
		{
			tag(x,i,-1);
			int tmp=dfs(x+1);
			if(tmp+board[x][i]>ma)
			{
				ma=tmp+board[x][i];
			}
			tag(x,i,1);
		}
	}
	return ma;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(use,0,sizeof(use));
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				cin>>board[i][j]; 
			}
		}
		cout<<setw(5)<<dfs(0)<<endl;
		cout<<cnt<<endl;
		cnt=0;
	}
	return 0;
}

