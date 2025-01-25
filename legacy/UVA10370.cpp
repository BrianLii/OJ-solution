#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int a[1020];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(3);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		double av=(double)sum/n;
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			if(a[i]>av)cnt++;
		}
		cout<<(double)cnt/n*100.0<<'%'<<endl;
	}
	return 0;
}

