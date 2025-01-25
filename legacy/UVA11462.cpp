#include<bits/stdc++.h>
using namespace std;
int a[2000020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(!n)return 0;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		for(int i=0;i<n;i++)
		{
			if(i)cout<<' ';
			cout<<a[i];	
		}
		cout<<endl;
	}
	return 0;
}

