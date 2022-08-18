#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define maxn 1000000
using namespace std;
typedef pair<int,int> pii;
int lead[maxn+20];
void init(int x=maxn)
{
	for(int i=0;i<=x;i++)
	{
		lead[i]=i;
	}
}
int find(int x)
{
	if(lead[x]==x)return x;
	else return lead[x]=find(lead[x]);
}
void U(int x,int y)
{
	lead[find(x)]=find(y);
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
struct E
{
	int a=0,b=0,w=0;
	E(int _a,int _b,int _c)
	{
		a=_a;
		b=_b;
		w=_c;
	}
	E(){}
};
bool cmp(const E &a,const E &b)
{
	return a.w<b.w;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	bool flag=0;
	while(cin>>n)
	{
		if(flag)cout<<endl;
		flag=1;
		int l,r,w;
		int ans=0;
		vector<E>edge;
		for(int i=0;i<n-1;i++)
		{
			cin>>l>>r>>w;
			ans+=w;
			edge.emplace_back(E(l,r,w));
		}
		cout<<ans<<endl;
		ans=0;
		int K;
		cin>>K;
		for(int i=0;i<K;i++)
		{
			cin>>l>>r>>w;
			edge.emplace_back(E(l,r,w));
		}
		sort(edge.begin(),edge.end(),cmp);
		int M;
		cin>>M;
		for(int i=0;i<M;i++)cin>>l>>r>>w;
		init();
		for(auto &i:edge)
		{
			if(same(i.a,i.b))continue;
			ans+=i.w;
			U(i.a,i.b);
		}
		cout<<ans<<endl;
	}
	return 0;
}

