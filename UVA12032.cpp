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
		int de=0;
		int k=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]-a[i-1]>k-de)
			{
				k=a[i]-a[i-1];
				de=1;
			}
			else if(a[i]-a[i-1]==k-de)
			{
				de++;
			}
		}
		cout<<"Case "<<j<<": ";
		cout<<k<<endl;	
	}
	
	return 0;
}

