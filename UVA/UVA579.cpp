#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	int h,m;
	while(~scanf("%lld:%lld",&h,&m))
	{
		if(!h&&!m)break;
		int NH=5*(h*60+m)%3600;
		int NM=60*m;
		double o=min(abs(NH-NM),abs(3600-abs(NH-NM)));
		printf("%0.3f\n",o/10);
	}
	return 0;
}

