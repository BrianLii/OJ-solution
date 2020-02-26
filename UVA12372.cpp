#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a<=20&&b<=20&&c<=20)cout<<"Case "<<i<<": good"<<endl;
		else cout<<"Case "<<i<<": bad"<<endl;
	}
	return 0;
}

