#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int a[600];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int md=n/2;
		int sum=0;
		for(int i=0;i<n;i++)sum+=abs(a[i]-a[md]);
		cout<<sum<<endl;
	}
	return 0;
}

