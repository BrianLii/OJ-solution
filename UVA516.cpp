#include<bits/stdc++.h>
using namespace std;
int a[50000];
int mii(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a;
		}
		a=a*a;
		b>>=1;
	}
	return ans;
}
void sai(int n)
{
	for(int i=2;i<n+100;i++)
	{
		if(!a[i])
		{
			for(int j=i;j<n+100;j+=i)
			{
				a[j]=i;
			}
		}
	}
}
void inshu(int x)
{
	while(x>1)
	{
		int in=a[x];
		cout<<in<<' ';
		int cnt=0;
		while(x%in==0)
		{
			x/=in;
			cnt++;
		}
		cout<<cnt;
		if(x>1)cout<<' ';
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sai(40000);
	string s;
	stringstream ss;
	while(getline(cin,s))
	{
		if(s=="0")return 0;
		ss.clear();
		ss<<s;
		int a1,a2;
		int x=1;
		while(ss>>a1>>a2)
		{
			x*=mii(a1,a2);
		}
		inshu(x-1);
		cout<<endl;
	}
	return 0;
}

