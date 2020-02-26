#include<bits/stdc++.h>
using namespace std;
int fac[1000020];
int use[1000020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> sq;
	for(int i=1;i<=1000;i++)
	{
		fac[i*i]=i;	
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=i+1;j<=1000;j++)
		{
			if(fac[i*i+j*j])
		}
	}
	return 0;
}

