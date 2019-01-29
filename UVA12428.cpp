#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	long long n,m;
	while(t--)
	{
		cin>>n>>m;
		//if(m==n-1)cout<<m<<endl;
		for(long long i=n-1;i>=0;i--)///i is num of key road
		{
			if((n-i)*(n-i-1)>=2*(m-i))
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
