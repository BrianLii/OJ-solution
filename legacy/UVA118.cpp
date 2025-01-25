#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dx[]{ 0,-1, 0, 1};
int dy[]{ 1, 0,-1, 0};
//        N  W  S  E
string nwse="NWSE";
int n,m;
int tag[200][200];
int conv(char c)
{
	if(c=='N')return 0;
	else if(c=='W')return 1;
	else if(c=='S')return 2;
	else if(c=='E')return 3;
}
int main()
{
	cin>>n>>m;
	int nx,ny;
	while(cin>>nx>>ny)
	{
		char c;
		cin>>c;
		int fa=conv(c);
		string s;
		cin>>s;
		bool fail=0;
		for(char i:s)
		{
			if(i=='R')fa=(fa-1+4)%4;
			else if(i=='L')fa=(fa+1)%4;
			else
			{
				if(nx+dx[fa]<0||ny+dy[fa]<0||
				   nx+dx[fa]>n||ny+dy[fa]>m)//will fall
				{
					if(tag[nx][ny])continue;
					else 
					{
						cout<<nx<<' '<<ny<<' '<<nwse[fa]<<" LOST"<<endl;
						tag[nx][ny]=1;
						fail=1;
						break;
					}
				}
				else 
				{
					nx+=dx[fa];
					ny+=dy[fa];
				}
			}
		}
		if(!fail)
		{
			cout<<nx<<' '<<ny<<' '<<nwse[fa]<<endl;
		}
	}
	return 0;
}
