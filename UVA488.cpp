#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
inline void wave(int x)
{
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=i;j++)cout<<i;
		cout<<endl;
	}
	for(int i=x-1;i>=1;i--)
	{
		for(int j=1;j<=i;j++)cout<<i;
		cout<<endl;
	}
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,f;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>f;
		for(int i=0;i<f;i++)
		{
			wave(a);
			if(t||i!=f-1)cout<<endl;	
		}
	}
	return 0;
}

