#include<bits/stdc++.h>
using namespace std;
int mod;
int fib(int x)
{
	if(x==1||x==0)return 1;
	return 1+fib(x-1)+fib(x-2);
}
struct sq
{
	vector<vector<int> >v;
	sq(int _a,int _b)
	{
		v.resize(_a);
		for(int i=0;i<_a;i++)
			v[i].resize(_b);
	}
	sq()
	{
		v.clear();
	}
};
void cross(const sq &a,const sq &b,sq &ans)
{
	if(a.v.empty())
	{
		ans=b;
		return;	
	}
	if(b.v.empty())
	{
		ans=a;
		return;	
	}
	sq tmp;
	int m=b.v.size();
	int n=b.v[0].size();
	int h=a.v.size();
	tmp.v.resize(h);
	for(int i=0;i<h;i++)
		tmp.v[i].resize(n);
	for(int i=0;i<h;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
			{
				tmp.v[i][j]+=a.v[i][k]*b.v[k][j];
				tmp.v[i][j]%=mod;
			}	
	ans=tmp;
}
int mii(int a,int b,int c)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%c;
		a=a*a%c;
		b>>=1;
	}
	return ans;
}
void out(sq &a)
{
	for(auto i:a.v)
	{
		for(int j:i)
			cout<<j<<' ' ;
		cout<<endl;
	}	
	cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long b;
	int cnt=0;
	while(cin>>b>>mod)
	{
		if(!b&&!mod)return 0;
		sq conv(3,3);
		sq start(1,3);
		conv.v[0][0]=0;conv.v[0][1]=1;conv.v[0][2]=0;
		conv.v[1][0]=1;conv.v[1][1]=1;conv.v[1][2]=0;
		conv.v[2][0]=0;conv.v[2][1]=1;conv.v[2][2]=1;
		start.v[0][0]=1;start.v[0][1]=1;start.v[0][2]=1;
		cout<<"Case "<<++cnt<<": "; 
		cout<<b<<' '<<mod<<' ';
		sq &a=conv;
		sq ans;
		while(b)
		{
			if(b&1)cross(ans,a,ans);
			cross(a,a,a);
			b>>=1; 
		}
		cross(start,ans,ans);
		cout<<ans.v[0][0]<<endl;
	}
	return 0;
}
/*
[ i, i+1 ,1 ] X [0 1 0
                 1 1 0
                 0 1 1]*/
