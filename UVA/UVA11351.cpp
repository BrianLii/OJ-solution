#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
int dp[100200];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]+k)%i;
	}
	cout<<dp[n]+1<<endl;
	return 0;
}

