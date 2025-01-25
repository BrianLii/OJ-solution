#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii; 
int a[100];
vector<int> v;
int n;
int u[100];
int uu[100];
bool dfs(int x,int le,int all,int K)
{
	//cout<<setw(2)<<x<<' '<<setw(2)<<le<<' '<<setw(2)<<all<<' '; 
	//for(int i=0;i<n;i++)cout<<u[i]<<' ';
	//cout<<endl;
	if(le==0)
	{
		if(all==0)return 1;
		for(int i=0;i<n;i++)
		{
			if(u[i])
			{
				for(int j=u[i];j>=1;j--)
				{
					if(K-v[i]*j>=0)
					{
						u[i]-=j;
						if(dfs(i+1,K-v[i]*j,all-v[i]*j,K))return 1;
						u[i]+=j;
					}
				}
				return 0;
			}
		}
	}
	else
	{
		if(x==n)return 0;
		for(int j=u[x];j>=0;j--)
		{
			if(le-v[x]*j>=0)
			{
				u[x]-=j;
				if(dfs(x+1,le-v[x]*j,all-v[x]*j,K))return 1;
				u[x]+=j;
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
		if(n==0)break;
		v.clear();
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sort(a,a+n,greater<int>());
		for(int i=0;i<n;i++)
		{
			int j;
			for(j=i;j<n;j++)if(a[j]!=a[i])break;
			u[v.size()]=j-i;
			uu[v.size()]=j-i;
			v.emplace_back(a[i]);
			i=j-1;
		}
		n=v.size();
		for(int i=1;i<=sum;i++)
		{
			if(sum%i==0)
			{
				for(int j=0;j<n;j++)u[j]=uu[j];
				if(dfs(0,i,sum,i))
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
	
}

