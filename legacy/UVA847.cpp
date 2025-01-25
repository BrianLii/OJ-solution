#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	while(cin>>n)
	{
		int cnt=0;
		long long now=1;
		while(now<n)
		{
			if((cnt&1))now*=2;
			else now*=9;
			cnt++;
		}
		if((cnt&1))cout<<"Stan wins."<<'\n';
		else cout<<"Ollie wins."<<'\n';
	}
	return 0;
}

