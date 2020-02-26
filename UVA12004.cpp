#include<bits/stdc++.h>
using namespace std;
int f[100020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[1]=0;
	for(int i=2;i<=100000;i++)
	{
		f[i]=f[i-1]+i-1;
	}
	int t;
	cin>>t;
	for(int i=1,n;i<=t;i++)
	{
		cout<<"Case "<<i<<": ";
		cin>>n;
		if(f[n]%2)cout<<f[n]<<"/2";
		else cout<<f[n]/2;
		cout<<'\n';
	}
	return 0;
}

