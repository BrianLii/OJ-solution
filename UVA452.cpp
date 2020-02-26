#include<bits/stdc++.h>
using namespace std;
int v[30];
vector<int> edge[30];
int dp[30];
int dfs(int x)
{
	if(dp[x])return dp[x];
	dp[x]=v[x];
	for(int i:edge[x])
	{
		dp[x]=max(dfs(i)+v[x],dp[x]);
	}
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	string trash;
	getline(cin,trash);
	getline(cin,trash);
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<27;i++)edge[i].clear();
		memset(v,0,sizeof(v));
		string inp;
		string all;
		while(getline(cin,inp))
		{
			if(inp=="")break;
			stringstream ss;
			ss<<inp;
			char now;
			ss>>now;
			all+=now;
			ss>>v[now-'A'];
			string tmp;
			ss>>tmp;
			for(char i:tmp)
			{
				edge[i-'A'].push_back(now-'A');
			}
		}
		int ans=0;
		for(char i:all)
		{
			if(!dp[i-'A'])
			{
				ans=max(dfs(i-'A'),ans);
			}
		}
		cout<<ans<<endl;
		if(t)cout<<endl;
	}
	return 0;
}
/*
2

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

A 5
B 3 A
D 2 A
C 2 B
F 2 CE
E 4 DC

*/

