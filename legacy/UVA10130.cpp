#include<bits/stdc++.h>
using namespace std;
int p[1100];
int w[1100];
int dp[1100][3020];
int cnt=1;
int use[1100][3020];
int dfs(int i,int noww)
{
	if(noww<0)return -2e9;
	if(noww==0)return 0;
	if(use[i][noww]==cnt)return dp[i][noww];
	use[i][noww]=cnt;
	if(i==1)return dp[i][noww]=(w[i]<=noww)?p[i]:0;
	return dp[i][noww]= max( dfs(i-1,noww-w[i])+p[i] , dfs(i-1,noww) );
}
int main()
{
	int n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>p[i]>>w[i];
		}
		int g;
		cin>>g;
		int tmp;
		long long sum=0;
		for(int i=0;i<g;i++)
		{
			cin>>tmp;
			sum+=dfs(n,tmp);
		}
		cout<<sum<<endl;
		cnt++;
	}
	
	return 0;
}

