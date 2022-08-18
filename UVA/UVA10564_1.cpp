#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50][50],dp[50][50][550];
char back[50][50][550];
int N,S;
bool back_t(int l,int x,int sum)
{
	cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
	if(l>N-1)
	{
		if(back[l][x][sum]=='L')
		{
			back_t(l+1,x,sum-a[l][x]);
		}
		else
		{
			back_t(l+1,x+1,sum-a[l][x]);
		}
	}
	else
	{
		if(back[l][x][sum]=='L')
			back_t(l+1,x-1,sum-a[l][x]);
		else
			back_t(l+1,x,sum-a[l][x]);
	}
}
ll dfs(int l,int x,int sum)
{
	if(dp[l][x][sum])return dp[l][x][sum];
	if(x<=0)return dp[l][x][sum]=0;
	if(sum<0)return dp[l][x][sum]=0;
	if(l<=N-1&&x>N-l)return dp[l][x][sum]=0;
	if(l>N-1&&x>l-N+2)return dp[l][x][sum]=0;
	if(l==0)
	{
		if(sum==a[l][x])return dp[l][x][sum]=1;
		else return dp[l][x][sum]=0;
	}
	if(l>N-1)
	{
		//cout<<l<<' '<<x<<' '<<sum-a[l][x]<<' '<<sum-a[l][x]<<endl;
		ll m=dfs(l-1,x,sum-a[l][x]),n=dfs(l-1,x-1,sum-a[l][x]);
		if(n)
		{
			
			back[l][x][sum]='L';
			cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		else if(m)
		{
			back[l][x][sum]='R';
			cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		return dp[l][x][sum]=n+m;
	}
	else
	{
		//cout<<l<<' '<<x<<' '<<sum-a[l][x]<<' '<<x+1<<endl;
		ll m=dfs(l-1,x,sum-a[l][x]),n=dfs(l-1,x+1,sum-a[l][x]);
		if(m)
		{
			back[l][x][sum]='L';
			cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		else if(n)
		{
			back[l][x][sum]='R';
			cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		return dp[l][x][sum]=n+m;
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
	ll sum=0;
	for(int i=1;i<=N;i++)
	{
		sum+=dfs(2*N-2,i,S);
	}
	cout<<sum<<endl;
	for(int i=1;i<=N;i++)
	{
		back_t(0,i,S);
		cout<<endl;
	}
	return 0;
}

