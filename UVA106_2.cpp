#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
struct node
{
	int a,b,c;
	node(int _a,int _b,int _c)
	{
		a=_a;
		b=_b;
		c=_c;
	}
	bool operator==(const node &_b)
	{
		return a==_b.a&&b==_b.b&&c==_b.c;
	}
	bool operator<(const node &_b)
	{
		return a==_b.a?(b==_b.b?(c<_b.c):b<_b.b):a<_b.a;
	}
};
vector<node> v;
int use[1000020];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,cnt=1;
	cin>>n;
	int ans1=0,ans2=n;
	for(int i=1,len=sqrt(n)+1;i<=len;i++)
	{
		for(int j=i+1;;j++)
		{
			int a=j*j-i*i,b=2*j*i,c=j*j+i*i;
			if(a>n||b>n||c>n)break;
			if(a>b)swap(a,b);
			int g=__gcd(a,__gcd(b,c));
			if(use[a]!=cnt)ans2--;
			if(use[b]!=cnt)ans2--;
			if(use[c]!=cnt)ans2--;
			cout<<a<<' '<<b<<' '<<c<<endl;
			use[a]=use[b]=use[c]=cnt;
			if(g==1)ans1++;
		    //v.emplace_back(a/g,b/g,c/g);
		}
	}
	cout<<ans1<<' '<<ans2<<endl;
	for(int i=0;i<=n;i++)cout<<setw(2)<<i<<' ';
	cout<<endl;
	for(int i=0;i<=n;i++)cout<<setw(2)<<use[i]<<' ';
	/*
	sort(v.begin(),v.end());
	vector<node>nv;
	for(auto &i:v)
	{
		if(!nv.empty()&&nv.back()==i)continue;
		else nv.emplace_back(i);	
	}	
	while(cin>>n)
	{
		node tmp(n,1000020,1000020);
		upper_bound(nv.begin(),nv.end(),tmp);
	}*/
	return 0;
}

