#include<bits/stdc++.h>
using namespace std;
long long cn2[1000020];
long long dp[1000020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(long long i=2;i<=1000000;i++)
	{
		cn2[i]=i*(i-1)/2;
	}
	for(long long i=3;i<=1000000;i++)
	{
		dp[i]=(i-1)*(i-2)/2-(cn2[i]-i/2)/2+dp[i-1]; 
	}
	int n;
	while(cin>>n)
	{
		if(n<3)return 0;
		cout<<dp[n]<<endl;		
	}
	return 0;
}

