#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int a[100];
bool vis[100];
int n;
vector<int> ans;
bool dfs(int x,int le)
{
	if(le==0)return 1;
	if(x==n)return 0;
	if(vis[x])return dfs(x+1,le);
	if(le<a[x])return dfs(x+1,le);
	else 
	{
		bool flag=0;
		ans.emplace_back(x);
		flag|=dfs(x+1,le-a[x]);
		if(flag)return 1;
		ans.pop_back();
		flag|=dfs(x+1,le);	
		return flag;
	}
}
bool check(int x,int sum)
{
	memset(vis,0,sizeof(vis));
	ans.clear();
	bool flag=1;
	for(int i=0;i<sum/x;i++)
	{
		flag&=dfs(0,x);
		if(flag==0)break;
		cout<<i<<endl;
		for(int i:ans)
			vis[i]=1;	
		ans.clear();
	}
	return flag;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];		
		}
		sort(a,a+n,greater<int>());
		cout<<dfs(0,21)<<endl;
		for(int i:ans)
		{
			cout<<i<<' ';
			vis[i]=1;		
		}
		cout<<endl;
		ans.clear();
		
		cout<<dfs(0,21)<<endl;
		for(int i:ans)
		{
			cout<<i<<' ';
			vis[i]=1;		
		}
		cout<<endl;
		ans.clear();
		
		cout<<dfs(0,21)<<endl;
		for(int i:ans)
		{
			cout<<i<<' ';
			vis[i]=1;		
		}
		cout<<endl;
		ans.clear();
		
		cout<<dfs(0,21)<<endl;
		cout<<dfs(0,21)<<endl;
		cout<<dfs(0,21)<<endl;
		/*
		int mi=INT_MAX;
		for(int i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				cout<<i<<":"<<endl;
				check(i,sum);	
			}
			if(sum%i==0)
			{
				int l=i,r=sum/i;
				if(l>mi)break;
				if(check(l,sum))mi=min(l,mi);
				else if(check(r,sum))mi=min(r,mi);
			}
		}
		cout<<mi<<endl;
		*/
		
	}
	return 0;
}

