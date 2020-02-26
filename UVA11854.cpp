#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b,c;
	while(cin>>a>>b>>c)
	{
		if(!a&&!b&&!c)
		{
			return 0;
		}
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
		if(a*a+b*b==c*c)cout<<"right\n";
		else cout<<"wrong\n"; 
	}
	
	return 0;
}

