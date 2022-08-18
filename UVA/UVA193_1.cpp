#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> ans,fans;
int ma;
vector<int> edge[200];
int clr[200];
void dfs(int l,int num)
{
	if(l>n)
	{
		if(num>=ma)
		{
			ma=num;
			fans=ans;
		}
		return;
	}
	bool haveblack=0;
	for(int i:edge[l])
	{
		haveblack|=(clr[i]==1);
		if(haveblack)break;	
	}
	if(!haveblack)
	{
		clr[l]=1;
		ans.push_back(l);
		if(n-l+num+1>=ma)dfs(l+1,num+1);
		ans.pop_back();
		clr[l]=0;
	}
	if(n-l+num>=ma)dfs(l+1,num);
}
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(clr,0,sizeof(clr));
		ans.clear();
		fans.clear();
		for(int i=0;i<=n;i++)edge[i].clear();
		ma=0;

		cin>>n>>k;
		while(k--)
		{
			int ta,tb;
			cin>>ta>>tb;
			edge[ta].push_back(tb);
			edge[tb].push_back(ta);
		}
		dfs(1,0);
		cout<<ma<<endl;
		for(int i=0;i<fans.size();i++)
		{
			if(i)cout<<' ';
			cout<<fans[i];
		}
		cout<<endl;
	}
	return 0;
}
