#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long  n,m;
	while(cin>>n>>m)
	{
		if(!m&&!n)return 0;
		if(m>n/2)m=n-m;
		long long ans=1;
		for(int i=1;i<=m;i++)
		{
			ans=ans*(n-m+i)/i;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

