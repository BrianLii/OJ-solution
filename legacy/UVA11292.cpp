#include<bits/stdc++.h>
using namespace std;
int dr[20200];
int kn[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m)
	{
		if(!n&&!m)break;
		for(int i=0;i<n;i++)
			cin>>dr[i];
		for(int i=0;i<m;i++)
			cin>>kn[i];
		sort(dr,dr+n);
		sort(kn,kn+m);
		long long ans=0;
		bool fail=0;
		for(int i=0,j=0;i<n;i++)
		{
			while(kn[j]<dr[i]&&j<m)j++;
			if(j==m)
			{
				fail=1;
				
				break;	
			}
			else ans+=kn[j++];
		}
		if(!fail)cout<<ans<<'\n';
		else cout<<"Loowater is doomed!\n";
	}
	return 0;
}

