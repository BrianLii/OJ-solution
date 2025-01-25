#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int a[100];
int n;
int vis[100];
bool dfs(int x,int le,int all,int K,int cnt)
{
	//cout<<x<<' '<<le<<' '<<all<<' '<<K<<' '<<cnt<<endl;
	//cin.get();
	if(le==0)
	{
		if(all==0)return 1;
		else return dfs(0,K,all,K,0);
	}
	if(x==n)return 0;
	if(vis[x])return dfs(x+1,le,all,K,cnt);	
	if(a[x]<=le)
	{
		vis[x]=1;
		bool flag=dfs(x+1,le-a[x],all-a[x],K,cnt+1);
		if(flag)return 1;
		vis[x]=0;
		if(cnt==0)return 0;
		else return dfs(x+1,le,all,K,cnt);		
	}
	else if(cnt==0)return 0;
	else return dfs(x+1,le,all,K,cnt);
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
		for(int i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				cout<<i<<endl;
				cout<<setfill('.')<<setw(10)<<""<<endl;
				dfs(0,i,sum,i,0);
				cin.get();
				//cout<<i<<' '<<dfs(0,i,sum,i,0)<<endl;
			}
		}
	}
	return 0;
}

