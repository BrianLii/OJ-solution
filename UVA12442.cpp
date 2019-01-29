#include<bits/stdc++.h>
using namespace std;
int next[50010];
struct DSU
{
	int lead[50010];
	int rank[50010];
	void _init(int n)
	{
		for(int i=1;i<=n;i++)
		{
			lead[i]=i;
			rank[i]=1;
		}
	}
	int find(int x)
	{
		if(lead[x]==x)return x;
		else return lead[x]=find(lead[x]);
	}
	void U(int x,int y)
	{
		rank[find(y)]+=rank[find(x)];
		lead[find(x)]=find(y);
	}
	int size(int x)
	{
		return rank[find(x)];
	}
};
DSU dsu;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		dsu._init(n+1);
	}
	return 0;
}

