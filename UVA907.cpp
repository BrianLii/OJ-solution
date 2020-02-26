#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
int a[610];
int n,k;
using namespace std;
int check(int x)
{
	int p=0;
	for(int i=0;i<k+1;i++)
	{
		int now=0;
		while(p<n&&now+a[p]<=x)
		{
			now+=a[p];
			p++;
		}
		if(p==n)return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>k)
	{
		n++;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];	
		}
		int l=0,r=sum;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}

