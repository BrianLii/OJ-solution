#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
//#include<iostream>
using namespace std;
typedef long long ll;
string s;
const ll limit = 2147483647;
stringstream ss;
long long convert(int from,int to)
{
	ss.clear();
	ss.str("");
	long long tmp;
	ss<<s.substr(from,to-from+1);
	ss>>tmp;
	return tmp;
}
ll dp[250];
ll dfs(int x)
{
	
	if(dp[x]!=0)return  dp[x];
	if(x<9)
	{
		return dp[x]=convert(0,x);
	}
	ll Max=-1;
	if(x==9)
	{
		if(convert(0,9)<=limit)
			return dp[x]=convert(0,x);
		else
		{
			ll tmp=dfs(x-1);
			if(tmp+convert(x,x)>Max)
			{
				Max = tmp+convert(x,x);
			}
			if(s[1]!='0')
			{
				tmp=dfs(0);
				if(tmp+convert(1,x)>Max)
				{
					Max = tmp+convert(1,x);
				}
			}
			return dp[x]=Max;
		}
	}
	for(int i=0;i<=8;i++)
	{
		if(s[x-i]!='0'||i==0)
		{
			ll tmp=dfs(x-i-1);
			if(tmp+convert(x-i,x)>Max)
			{
				Max = tmp+convert(x-i,x);
			}
		}
		
	}
	if(convert(x-9,x)<=limit)
	{
		ll tmp=dfs(x-9-1);
		if(tmp+convert(x-9,x)>Max)
		{
			Max = tmp+convert(x-9,x);
		}
	}
	return dp[x]=Max;
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<dfs(s.size()-1)<<endl;
		memset(dp,0,sizeof(dp));
	}
}

