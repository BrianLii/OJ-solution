#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cout<<"PERFECTION OUTPUT"<<endl;
	while(cin>>n)
	{
		if(!n)break;
		int sum=0;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i)continue;
			int j=n/i;
			sum+=i;
			if(j!=i)sum+=j;
		}
		sum-=n;
		cout<<setw(5)<<n<<"  ";
		if(sum==n)cout<<"PERFECT"<<endl;
		else if(sum<n)cout<<"DEFICIENT"<<endl;
		else cout<<"ABUNDANT"<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
	return 0;
}

