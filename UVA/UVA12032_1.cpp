#include<bits/stdc++.h>
using namespace std;
int a[100200];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int k=a[n]-a[n-1];
		for(int i=n-1;i>0;i--)
		{
			if(a[i]-a[i-1]==k)k++;
			else if(a[i]-a[i-1]>k)k=a[i]-a[i-1];
		}
		cout<<"Case "<<j<<": ";
		cout<<k<<'\n';	
	}
	
	return 0;
}

