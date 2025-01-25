#include<bits/stdc++.h>
using namespace std;
int a[20300];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int st=0;
		int ans=0;
		st+=n%3;
		for(int i=st;i<n;i+=3)
		{
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

