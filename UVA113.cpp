#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long double p,n;
	while(cin>>n>>p)
	{
		long double ans=pow(p,1.0/n);
		cout<<(int)(ans+0.5)<<endl; 	
	}
	return 0;
}

