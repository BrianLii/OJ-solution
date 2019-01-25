#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct cm
{
	int a,b,w;
	cm(int _a,int _b,int _w)
	{
		a=_a;
		b=_b;
		w=_w;
	}
	cm()
	{
		a=w=b=0;
	}
};
cm a[30030];
bool operator < (const cm &_a,const cm &_b)
{
	return _a.b==_b.b?_a.a<_b.a:_a.b<_b.b;
}
bool cmp(int p,int q)
{
	return a[p]<a[q];
}
int idx[30030];
int dp[200020];
const int sh=5;
#define endl '\n'
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int ct=1;ct<=t;ct++)
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].a>>a[i].b>>a[i].w;
			a[i].b=a[i].a+a[i].b-1;
			idx[i]=i;
		}
		sort(a,a+n);
		int j=0;
		for(int i=0;i<=a[idx[n-1]].b;i++)
		{
			dp[i+sh]=dp[i-1+sh];
			while(a[idx[j]].b==i)/*if(i==a[idx[j].b)*/
			{
				if(i==a[idx[j]].b)dp[i+sh]=max(a[idx[j]].w+dp[a[idx[j]].a-1+sh],dp[i+sh]);
				j++;
			}
		}
		cout<<"Case "<<ct<<": ";
		cout<<dp[a[idx[n-1]].b+sh]<<endl;
	}
	return 0;
}

