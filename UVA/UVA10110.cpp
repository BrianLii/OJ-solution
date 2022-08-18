#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	while(cin>>x)
	{
		if(!x)break;
		int l=sqrt(x)-3;
		int r=l+6;
		bool flag=0;
		for(int i=l;i<=r;i++)
		{
			if(i*i==x)
			{	
				cout<<"yes"<<endl;
				flag=1;
				break;
			}
		}
		if(!flag) cout<<"no"<<endl;
	}
	return 0;
}

