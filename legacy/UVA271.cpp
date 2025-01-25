#include<bits/stdc++.h>
using namespace std;
string s;
bool dp[300][300];
int use[300][300];
bool check(int l,int r)
{
	if(use[l][r])return dp[l][r];
	use[l][r]=1;
	//cout<<l<<' '<<r<<endl;
	if(l>r)return dp[l][r]=0;
	if(l==r)
	{
		if(s[l]<='z'&&s[l]>='p')return dp[l][r]=1;
		else return dp[l][r]=0;
	}
	if(s[l]=='N')
	{
		if(l==r)return dp[l][r]=0;
		else return dp[l][r]=check(l+1,r);	
	}
	else if(s[l]=='C'||s[l]=='D'||s[l]=='E'||s[l]=='I')
	{
		bool flag=0;
		for(int i=l+1;i<r&&!flag;i++)
		{
			flag|=check(l+1,i)&&check(i+1,r);
		}
		return dp[l][r]=flag;
	}
	else 
	{
		return dp[l][r]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s)
	{
		memset(use,0,sizeof(use));
		cout<<(check(0,s.size()-1)?"YES":"NO")<<'\n';
	}
	return 0;
}

