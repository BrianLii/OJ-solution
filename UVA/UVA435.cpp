#include<bits/stdc++.h>
using namespace std;
int a[50];
int dp[25][1020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p;
	cin>>p;
	int sum=0;
	for(int i=0;i<p;i++)
	{
		cin>>a[i];		
		sum+=a[i];
	}
	
	int l=sum/2-a[p-1]+1;
	int r=sum/2;
	dp[0][a[0]]=1;
	dp[0][0]=1;
	for(int i=1;i<=p-2;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			if(j<a[i])dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
		}
	}
	int ans=0;
	cout<<l<<' '<<r<<endl;
	for(int i=l;i<=r;i++)
	{
		ans+=dp[p-2][i];
	}
	cout<<ans<<endl;
	return 0;
}

