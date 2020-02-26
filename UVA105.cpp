#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define maxn 10000
using namespace std;
int h[maxn+20];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int l,H,r;
	while(cin>>l>>H>>r)
	{
		for(int i=l;i<=r;i++)
		{
			h[i]=max(h[i],H);
		}
	}
	int now=0;
	bool flag=0;
	for(int i=0;i<=maxn;i++)
	{
		if(h[i]!=now)
		{
			if(flag)cout<<' ';
			if(h[i]>now)cout<<i;
			else cout<<i-1;
			cout<<' '<<h[i];
			now=h[i];
			flag=1;
		}
	}
	cout<<endl;
	return 0;
}

