#include<bits/stdc++.h>
using namespace std;
long long qp(long long a,long long b,long long c)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%c;			
		}
		b>>=1;
		a=a*a%c;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	while(cin>>a>>b>>c)
	{
		cout<<qp(a,b,c)<<endl;
	}
	return 0;
}

