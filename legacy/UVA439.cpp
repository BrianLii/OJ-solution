#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dx[]{-1,-1,1, 1,-2,-2,2, 2};
int dy[]{ 2,-2,2,-2, 1,-1,1,-1};
struct sta
{
	int x,y,d;
	sta(int a,int b,int c)
	{
		x=a;
		y=b;
		d=c;
	}
	sta()
	{
		x=y=d=0;
	}
};
int vis[10][10];
int main() {
	string s1,s2;
	int y1,y2,x1,x2;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s1>>s2)
	{
		memset(vis,0,sizeof(vis));
		x1=s1[0]-'a';
		x2=s2[0]-'a';
		y1=s1[1]-'1';
		y2=s2[1]-'1';
		queue<sta> q;
		q.push(sta(x1,y1,0));
		
		vis[x1][y1]=1;
		while(!q.empty())
		{
			int nx=q.front().x,ny=q.front().y,nd=q.front().d;
			q.pop();
			if(nx==x2&&ny==y2)
			{
				cout<<"To get from "<<s1<<" to "<<s2<<" takes ";
				cout<<nd<<" knight moves."<<'\n';
				break;
			}
			for(int i=0;i<8;i++)
			{
				if(nx+dx[i]<=7&&nx+dx[i]>=0&&
				   ny+dy[i]<=7&&ny+dy[i]>=0&&
				   !vis[nx+dx[i]][ny+dy[i]])
				{
					q.push(sta(nx+dx[i],ny+dy[i],nd+1));
					vis[nx+dx[i]][ny+dy[i]]=1;
				}
			}
		}
	}
	return 0;
}

