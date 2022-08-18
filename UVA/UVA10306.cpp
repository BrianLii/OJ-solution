#include<bits/stdc++.h>
#define INF (0x3f3f3f3f)
using namespace std;
int x[42],y[42];
int dp[42][320][320];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,s;
	cin>>m>>s;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int jj=0;jj<=m;jj++)
	{
		for(int i=0;i<305;i++)
			for(int j=0;j<305;j++)
				dp[jj][i][j]=INF;
	}
	dp[0][0][0]=0;
	for(int i=1;i<=m;i++)
	for(int j=0;j<305;j++)
	for(int k=0;k<305;k++)
	for(int a=0;a*x[i]<=j&&a*y[i]<=k;a++)
	{
		//cout<<i<<' '<<j<<' '<<k<<endl;
		if(j-x[i]*a>=0&&j-x[i]*a<=300&&
		   k-y[i]*a>=0&&k-y[i]*a<=300)
		dp[i][j][k]=min(dp[i-1][j-x[i]*a][k-y[i]*a]+a,dp[i-1][j][k]);
		//cout<<dp[i][j][k]<<endl;
	}
	int mii=INT_MAX;
	for(int i=0;i<=s;i++)
		for(int j=0;j<=s;j++)
		{
			if(i*i+j*j==s*s)
			{
				mii=min(mii,dp[m][i][j]);
			}
		}
	cout<<mii<<endl;
	return 0;
}

