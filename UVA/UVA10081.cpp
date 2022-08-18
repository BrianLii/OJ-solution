#include<bits/stdc++.h>
using namespace std;
double dp[120][10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k,n;
	cout<<fixed<<setprecision(5);
	while(cin>>k>>n)
	{
		if(k==0)
		{
			cout<<"100.00000"<<endl;
			continue;
		}
		for(int i=0;i<=k;i++)
		{
			dp[1][i]=1/(k+1.0);
		}
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
			dp[i][k]=dp[i-1][k]+dp[i-1][k-1];
			dp[i][0]/=(k+1.0);
			dp[i][k]/=(k+1.0);
			for(int j=1;j<k;j++)
			{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
				dp[i][j]/=(k+1.0);
			}
		}
		double sum=0;
		/*for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
			{
				cout<<dp[i][j]<<' ';
			}
			cout<<endl;
		}*/
		for(int i=0;i<=k;i++)sum+=dp[n][i];
		cout<<sum*100<<endl;
		memset(dp,0,sizeof(dp));
	}
	
	
}

