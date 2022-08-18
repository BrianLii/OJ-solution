#include<bits/stdc++.h>
using namespace std;
struct fib 
{
	int a[120]={0};
};
operator << (fib &a,string &s)
{
	auto it=s.end();
	for(int i=0;i<s.size();i++)
	{
		it--;
		a.a[i]=(*it)-'0';
	}
}
fib operator + (fib a,fib b)
{
	fib ans;
	for(int i=0;i>=100;i++)
	{
		ans.a[i]+=a.a[i];
		if(a.a[i]>1)
		{
			while(1)
			{
				if((++a.a[i+1])>1);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	return 0;
}

