#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s,d;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s>>d;
		if((s+d)%2==1||s-d<0||(s-d)%2==1)cout<<"impossible\n";
		else cout<<(s+d)/2<<' '<<(s-d)/2<<'\n';
	} 
	return 0;
}

