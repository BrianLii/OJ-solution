#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
//#include<iostream>
using namespace std;
string s;
long long num,ans=-1,limit=2147483647;
string lim="2147483647";
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
void dfs(int x)
{
	if(x==-1)
	{
		if(num>ans)ans=num;
		return;
	}
	else if(x<9)
	{
		num+=convert(0,x);
		dfs(-1);
		num-=convert(0,x);
	}
	else if(x==9)
	{
		if(convert(0,9)<=limit)
		{
			num+=convert(0,9);
			dfs(-1);
			num-=convert(0,9);
		}
		else
		{
			num+=s[x]-'0';
			dfs(x-1);
			num-=s[x]-'0';
			num+=convert(1,x);
			dfs(0);
			num-=convert(1,x);
		}
	}
	else
	{
		for(int i=1;i<=9;i++)
		{
			num+=convert(x-i+1,x);
			dfs(x-i);
			num-=convert(x-i+1,x);
		}
		if(convert(x-10+1,x)<=limit)
		{
			num+=convert(x-10+1,x);
			dfs(x-10);
			num-=convert(x-10+1,x);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		num=0;
		ans=-1;
		cin>>s;
		dfs(s.size()-1);
		cout<<ans<<endl;
	}
	
}

