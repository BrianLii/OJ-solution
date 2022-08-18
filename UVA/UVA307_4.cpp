#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int n;
int a[100];
bool vis[100];
bool dfs(int x,int le,int all,int K,int cnt)
{
	cout<<x<<' '<<le<<' '<<all<<' '<<K<<' '<<cnt<<endl;
	if(le==0)
	{
		if(all==0)return 1;
		for(int i=0;i<n;i++)
		{
			if(!vis[i])
			{
				if(a[i]>K)return 0;
				vis[i]=1;
				if(dfs(i+1,K-a[i],all-a[i],K,1))return 1;
				vis[i]=0;
				return 0;
			}
		}
	}
	else
	{
		for(int i=x;i<n;i++)
		{
			if(!vis[i]&&a[i]<=le)
			{
				vis[i]=1;
				if(dfs(i+1,le-a[i],all-a[i],K,cnt+1))return 1;
				vis[i]=0;
			}
		}
		return 0;
	}
	
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
		cout<<sum<<endl;
		cout<<dfs(0,21,sum,18,0)<<endl;
		/*
		for(int i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				memset(vis,0,sizeof(vis));
				if(dfs(0,i,sum,i,0))
				{
					cout<<i<<endl;
					break;	
				}
			}
		}
		*/
	}
	return 0;
}

