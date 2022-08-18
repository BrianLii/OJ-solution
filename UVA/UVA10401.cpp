#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
long long dp[20][20];
long long use[20][20];
long long conv(long long i)
{
	if(s[i]<='9'&&s[i]>='0')return s[i]-'0';
	else return s[i]-'A'+10;
}
long long dfs(long long l,long long p)
{
	if(s[l]!='?'&&conv(l)!=p)return 0;
	if(l==0)return 1;
	if(use[l][p])return dp[l][p];
	use[l][p]=1;
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(abs(i-p)>=2)
		{
			ans+=dfs(l-1,i);
		}
	}
	return dp[l][p]=ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s)
	{
		memset(use,0,sizeof(use));
		n=s.size();
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			ans+=dfs(n-1,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}

