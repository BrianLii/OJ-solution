#include<bits/stdc++.h>
using namespace std;
int a[620];
int sum[620];
int dp[620][350];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k)
	{
		for(int i=1;i<=n+1;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n+1;i++)
		{
			sum[i]=sum[i-1]+a[i];
		}
		//for(int i=0;i<=n+1;i++)cout<<sum[i]<<' ';
		//cout<<endl;
		//start = 0 ,end = n+1
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=k+1;j++)
				dp[i][j]=INT_MAX;
		dp[0][0]=0;
		for(int i=1;i<=k+1;i++)
		{
			for(int j=0;j<=n+1;j++)
			{
				for(int ii=j+1;ii<=n+1;ii++)
				{
					dp[ii][i]=min(dp[ii][i],max(dp[j][i-1],sum[ii]-sum[j]));
				}
			}
		}
		cout<<dp[n+1][k+1]<<endl;
	}
	return 0;
}

