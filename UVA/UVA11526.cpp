#include<bits/stdc++.h>
using namespace std;
long long H(int x)
{
	long long ans=0;
	for(int i=1;i<=x;i++)
	{
		ans+=(x/i)*(x/(x/i)-i+1);
		i=x/(x/i);
	}
	return ans;
}
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
		cout<<H(n)<<endl;
	}
	return 0;
}

