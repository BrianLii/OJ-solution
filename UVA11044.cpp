#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		n-=2;
		m-=2;
		cout<<(n/3+bool(n%3))*(m/3+bool(m%3))<<endl;
	}
	return 0;
}

