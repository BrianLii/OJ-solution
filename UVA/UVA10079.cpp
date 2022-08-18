#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(n<0)break;
		cout<<1+n*(n+1)/2<<endl;
	}
	return 0;
}

