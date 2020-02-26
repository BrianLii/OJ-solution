#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	while(cin>>n)
	{
		long long l=(n+1LL)/2LL;
		long long num=(n+1LL)/2LL*l;
		cout<<(num*2LL-3LL)*3LL<<endl;
	}
	return 0;
}

