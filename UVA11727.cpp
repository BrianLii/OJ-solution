#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cout<<"Case "<<i<<": ";
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a>b)swap(a,b);
		cout<<b<<endl;
	}
	
	return 0;
}

