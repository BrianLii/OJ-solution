#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string s[510];
struct E
{
	int a,b,w;
	E(int _a,int _b,int _w)
	{
		a=_a;
		b=_b;
		w=_w;
	}
	E()
	{
		a=b=w=0;
	}
};
vector<E> edges;
bool operator <(const E &_a,const E &_b)
{
	return _a.w<_b.w;
}
int cal(int a,int b)
{
	int rec=0;
	for(int i=0;i<4;i++)
	{
		int d=abs(s[a][i]-s[b][i]);
		if(d>5)d=10-d;
		rec+=d;
	}
	return rec;
}
struct DSU
{
	int lead[610];
	void init(int x=510)
	{
		for(int i=0;i<=x;i++)lead[i]=i;
	}
	int find(int x)
	{
		if(lead[x]==x)return x;
		else return lead[x]=find(lead[x]);
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
	void U(int x,int y)
	{
		lead[find(x)]=find(y);
	}
};
DSU dsu;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		edges.clear();
		cin>>n;
		s[0]="0000";
		for(int i=1;i<=n;i++)
		{
			cin>>s[i];
		}
		int mi=INT_MAX;
		for(int i=1;i<=n;i++)
		{
			mi=min(mi,cal(0,i));
			for(int j=i+1;j<=n;j++)
			{
				edges.emplace_back(i,j,cal(i,j));
			}
		}
		sort(edges.begin(),edges.end());
		int ans=0;
		dsu.init();
		for(auto i:edges)
		{
			if(dsu.same(i.a,i.b))continue;
			else
			{
				ans+=i.w;
				//cout<<i.w<<endl;
				dsu.U(i.a,i.b);
			}
		}
		cout<<ans+mi<<'\n';
	}
	return 0;
}
