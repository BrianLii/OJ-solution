#include<bits/stdc++.h>
using namespace std;
int a[75];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(!n)break;
		for(int i=0;i<n;i++)cin>>a[i];
		int tp=0,bm=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(__gcd(a[i],a[j])==1)tp++;
				bm++;
			}
		}
		if(tp==0)cout<<"No estimate for this data set."<<endl;
		else cout<<fixed<<setprecision(6)<<sqrt(6.0*bm/(double)tp)<<endl;
	}
	return 0;
}

