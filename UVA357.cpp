#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define maxn 30000
using namespace std;
int dp[maxn+20];
int face[]{1,5,10,25,50};
signed main()
{
	dp[0]=1;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j+face[i]<=maxn;j++)dp[j+face[i]]+=dp[j];
	}
	int n;
	while(~scanf("%lld",&n))
	{
		if(dp[n]==1)printf("There is only 1 way to produce %lld cents change.\n",n);
		else printf("There are %lld ways to produce %lld cents change.\n",dp[n],n);
	}
	return 0;
}

