#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int cnt=1;
	while(t--)
	{
		cout<<"Case "<<cnt++<<": ";
		int a,b;
		cin>>a>>b;
		if(!(a&1))a++;
		if(!(b&1))b--;
		if(a>b)cout<<0<<endl;
		else 
		{
			cout<<(a+b)*((b-a)/2+1)/2<<'\n';
		}
	}
	return 0;
}

