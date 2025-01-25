#include<bits/stdc++.h>
using namespace std;
const int sh = 2002;
int a[2010];
int dp[10010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		int ma=1;
		int l=1,r=1;
		memset(dp,0,sizeof(dp));
		dp[1+sh]=a[0];
		for(int j=0;j<n;j++)
		{
			if(a[j]>dp[r+sh])dp[(++r)+sh]=a[j];
			else if(a[j]<dp[l+sh])dp[(--l)+sh]=a[j];
			else
			{
				int *p=lower_bound(dp+l+sh,dp+r+1+sh,a[j]);
				*p=a[j];
			}
		}
		cout<<(r-l+1)<<endl;
		/*for(int i=0;i<n;i++)//choose one that must take 
		{
			int l=1,r=1;
			memset(dp,0,sizeof(dp));
			dp[1+sh]=a[i];
			for(int j=i+1;j<n;j++)
			{
				if(a[j]>dp[r+sh])dp[(++r)+sh]=a[j];
				else if(a[j]<dp[l+sh])dp[(--l)+sh]=a[j];
				else
				{
					int *p=lower_bound(dp+l+sh,dp+r+1+sh,a[j]);
					*p=a[j];
				}
			}
			ma=max(r-l+1,ma);
		}
		cout<<ma<<endl;*/
	}
	return 0;
}

