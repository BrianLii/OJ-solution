#include<bits/stdc++.h>
using namespace std;
long long x[50],y[50];
long long dp[320][320];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		int m,s;
		cin>>m>>s;
		for(int i=0;i<m;i++)
		{
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<m;i++)
		{
			dp[x[i]][y[i]]=1;
			for(int j=0;j<=s;j++)
				for(int k=0;k<=s;k++)
					if(j+x[i]<=300&&k+y[i]<=300&&dp[j][k])
					{
						dp[j+x[i]][k+y[i]]=
						(dp[j+x[i]][k+y[i]])?
						min(dp[j+x[i]][k+y[i]],dp[j][k]+1)
						:dp[j][k]+1;
						
					}
		}
		long long mi=LLONG_MAX;
		for(int i=0;i<=s;i++)
			for(int j=0;j<=s;j++)
				if(i*i+j*j==s*s&&dp[i][j])
					{
						mi=min(mi,dp[i][j]);
					}
		if(mi==LLONG_MAX)cout<<"not possible"<<endl;
		else cout<<mi<<endl;
	}
	return 0;
}

