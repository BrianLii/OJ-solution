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
	for(int ii=1;ii<=T;ii++)
	{
		int n;
		cin>>n;
		int tmp,ma=0;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			ma=max(ma,tmp);
		}
		cout<<"Case "<<ii<<": "<<ma<<endl;
	}
	return 0;
}

