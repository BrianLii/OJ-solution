#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define maxn 1000000
using namespace std;
int dp[maxn+20];
int count(int n)
{
	int cnt=1;
	while(n!=1)
	{
		if(n%2)n=3*n+1;
		else n/=2;
		cnt++;
	}
	return cnt;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=maxn;i++)dp[i]=count(i);
	int i,j;
	while(cin>>i>>j)
	{
		cout<<i<<' '<<j<<' ';
		if(i>j)swap(i,j);
		int ans=dp[i];
		for(int ii=i;ii<=j;ii++)
		{
			ans=max(ans,dp[ii]);
		}
		cout<<ans<<endl;
	}
	return 0;
}

