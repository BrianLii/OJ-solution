#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int n;
int a[1000020];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int l,r;
		if(n%2==0)
		{
			int mid=n/2;
			l=a[mid-1];
			r=a[mid];
		}
		else
		{
			int mid=n/2;
			l=a[mid];
			r=a[mid];
		}
		cout<<l<<' ';
		int ans=0;
		for(int i=0;i<n;i++)if(l<=a[i]&&a[i]<=r)ans++;
		cout<<ans<<' '<<r-l+1<<endl;
	}
	
	return 0;
}

