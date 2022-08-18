#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int dp[100020];
int SUM(int x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	for(int i=1;i<=100000;i++)
	{
		int tmp=SUM(i)+i;
		if(tmp>100000)continue;
		if(!dp[tmp])dp[tmp]=i;
	}
	while(T--)
	{
		int n;
		cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}

