#include<bits/stdc++.h>
using namespace std;
int a[25],dp[25][500],use[25][500];
int cnt=1;
bool dfs(int l,int sum)
{
	//if(use[l][sum]==cnt)return dp[l][sum];
	use[l][sum]=cnt;
	if(sum<0)return dp[l][sum]=0;
	if(sum==0)return dp[l][sum]=1;
	if(l==0)
	{
		if(sum==0)return dp[l][sum]=0;
		else return dp[l][sum]=1;
	}
	return dp[l][sum]=dfs(l-1,sum-a[l])||dfs(l-1,sum);
}
int main()
{
	int n,sum=0;
	int t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum&1)
	{
		cout<<"NO\n";
	}
	cout<<sum/2;
	cout<<dfs(n,sum/2);
	return 0;
}

