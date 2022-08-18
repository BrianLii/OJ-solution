#include<bits/stdc++.h>
using namespace std;
int to[50020];
int n;
int in[50020];
int vis[50020];
int rec(int x)
{
	vis[x]=1;
	if(vis[to[x]])return 1;
	else return rec(to[x])+1;
}
int rec2(int x,int ed)
{
	vis[x]=1;
	if(to[x]==ed)return 1;
	else return rec2(to[x],ed)+1;
}
int main()
{
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		cin>>n;
		int ma=1;
		int num=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			int u,v;
			cin>>u>>v;
			to[u]=v;
			in[v]++;
		}
		for(int i=1;i<=n;i++)
		{
			if(in[i]==0)
			{
				int tmp=rec(i);
				if(tmp>ma)
				{
					ma=tmp;
					num=i;
				}
				else if(tmp==ma&&i<num)
				{
					ma=tmp;
					num=i;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&in[i]==1)
			{
				int tmp=rec2(i,i);
				if(tmp>ma)
				{
					ma=tmp;
					num=i;
				}
				else if(tmp==ma&&i<num)
				{
					ma=tmp;
					num=i;
				}
			}
		}
		cout<<"Case "<<++cnt<<": ";
		cout<<num<<endl;
	}
}
