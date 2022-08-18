#include<bits/stdc++.h>
using namespace std;
long long dp[40000][12];
int penny[]{5,10,20,50,100,200,500,1000,2000,5000,10000};
long long dfs(int x,int MAX)
{
	if(x==0)return dp[x][MAX]=1;
	if(x<0)return 0;
	if(x==1)return dp[x][MAX]=1;
	if(dp[x][MAX])return dp[x][MAX];
	long long sum=0;
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
	double n;
	stringstream ss;
	while(cin>>n)
	{
		if(n==0)return 0;
		string output;
		ss.clear();
		ss.str("");
		int x=n*100;
		ss<<n;
		ss>>output;
		for(int i=0;i<6-output.size();i++)cout<<' ';
		cout<<output;
		ss.clear();
		ss.str("");
		ss<<dfs(x,10);
		ss>>output;
		for(int i=0;i<17-output.size();i++)cout<<' ';
		cout<<output<<'\n';
	}
	return 0;
}

