#include<bits/stdc++.h>
using namespace std;
int dp[8000][6];
int penny[]{1,5,10,25,50};
int dfs(int x,int MAX)
{
	
	if(x==0)return dp[x][MAX]=1;
	if(x<0)return 0;
	if(x==1)return dp[x][MAX]=1;
	if(dp[x][MAX])return dp[x][MAX];
	int sum=0;
	for(int i=0;i<=MAX;i++)
	{
		sum+=dfs(x-penny[i],i);
	}
	return dp[x][MAX]=sum;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		cout<<dfs(n,4)<<endl;
	}
	return 0;
}

