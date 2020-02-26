#include<bits/stdc++.h>
using namespace std;
int cp[][3]{{0,1,2},{1,2,0},{0,2,1}};
struct node
{
	int a[3];
	void sort()
	{
		if(a[0]>a[1])swap(a[0],a[1]);
		if(a[1]>a[2])swap(a[1],a[2]);
		if(a[0]>a[1])swap(a[0],a[1]);
	}
};
node a[100];
int adj[100][100];
int dp[100];
int n;
int ma;
int dfs(int x)
{
	if(dp[x]>0)return dp[x];
	dp[x]=a[x].a[2];
	for(int i=0;i<n*3;i++)
	{
		if(adj[x][i])
		{
			dp[x]=max(a[x].a[2]+dfs(i),dp[x]);
		}
	}
	ma=max(dp[x],ma);
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0;
	while(cin>>n)
	{
		if(!n)return 0;
		cout<<"Case "<<++cnt<<": maximum height = ";
		memset(adj,0,sizeof(adj));
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
		ma=0;
		for(int i=0;i<n*3;i+=3)
		{
			cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
			a[i].sort();
			for(int j=1;j<3;j++)
			{
				a[i+j].a[0]=a[i].a[cp[j][0]];
				a[i+j].a[1]=a[i].a[cp[j][1]];
				a[i+j].a[2]=a[i].a[cp[j][2]];
			}
		}
		for(int i=0;i<n*3;i++)
			for(int j=0;j<n*3;j++)
			{
				if(i==j)continue;
				//j smaller than i == i to j
				if(a[j].a[0]<a[i].a[0]&&a[j].a[1]<a[i].a[1])
				{
					adj[i][j]=1;
				}
			}
		for(int i=0;i<n*3;i++)
			dfs(i);
		cout<<ma<<endl;
	}
	return 0;
}

