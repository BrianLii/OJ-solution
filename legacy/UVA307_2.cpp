#include<bits/stdc++.h>
///#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int n;
int a[100];
bool vis[100];
bool dfs(int x,int le,int ale,int ord)
{
	cout<<x<<' '<<le<<' '<<ale<<endl;
	cin.get();
	if(le==0)
	{
		if(ale==0)return 1;
		else return dfs(0,ord,ale,ord); 
	}
	if(x==n)return 0;
	
	if(vis[x]||le<a[x])return dfs(x+1,le,ale,ord);
	else
	{
		vis[x]=1;
		bool flag=dfs(x+1,le-a[x],ale-a[x],ord);
		vis[x]=0;
		if(flag)return 1;
		return dfs(x+1,le,ale,ord);
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
		int mi=INT_MAX;
		for(int i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				int l=i,r=sum/i;
				if(l>mi)break;
				if(dfs(0,l,sum,l))mi=min(l,mi);
				else if(dfs(0,r,sum,r))mi=min(r,mi);
			}
		}
		cout<<mi<<endl;
	}
	return 0;
}

