#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define maxn 100
using namespace std;
int dp[maxn+10];
void build(int n,int k)
{
	dp[1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]+k)%i;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(!n)break;
		for(int i=1;i<n;i++)
		{
			build(n-1,i);
			if(dp[n-1]+2==13)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
	
}

