#include<bits/stdc++.h>
using namespace std;
int a[50][50],dp[50][50][550];
int N,S;
int dfs(int l,int x,int sum)
{
	if(x<=0)return 0;
	if(sum<0)return 0;
	if(dp[l][x][sum])
	{
		cout<<l<<" : "<<x<<" : "<<sum<<" : "<<dp[l][x][sum]<<endl;
		return dp[l][x][sum];
	}
	if(l<=N-1)
	{
		if(l==0)
		{
			if(sum==a[l][x])
			{
				return dp[l][x][sum]=1;
			}
			else return dp[l][x][sum]=0;
		}
		return dp[l][x][sum]=dfs(l-1,x,sum-a[l][x])+dfs(l-1,x+1,sum-a[l][x]);
	}
	else
	{
		/*if(l==2*N-2)
		{
			if(sum==a[l][x])
			{
				return dp[l][x][sum]=1;
			}
			else return dp[l][x][sum]=0;
		}*/
		return dp[l][x][sum]=dfs(l-1,x,sum-a[l][x])+dfs(l-1,x-1,sum-a[l][x]);
	}
	
}
int main()
{
	
	cin>>N>>S;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N-i;j++)
		{
			cin>>a[i][j+1];
		}
	}
	for(int i=1;i<N;i++)
	{
		for(int j=0;j<i+1;j++)
		{
			cin>>a[i+N-1][j+1];
		}
	}
	int sum=0;
	for(int i=1;i<=N;i++)
	{
		sum+=dfs(2*N-2,i,S);
	}
	cout<<sum;
	return 0;
}

