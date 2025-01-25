#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[2020];
int lis[2020],lds[2020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		memset(lis,0,sizeof(lis));
		memset(lds,0,sizeof(lds));
		int n;
		cin>>n;
		if(!n)
		{
			cout<<0<<endl;
			
			continue;
		}
		for(int i=0;i<n;i++)cin>>a[i];
		lis[1]=a[n-1];
		lds[1]=a[n-1];
		int ic=1,de=1;
		int ma=1;
		for(int i=n-2;i>=0;i--)
		{
			int *p=lower_bound(lis+1,lis+ic+1,a[i]);
			int *q=lower_bound(lds+1,lds+de+1,a[i],greater<int>());
			if(a[i]>lis[ic])lis[++ic]=a[i];	
			if(a[i]<lds[de])lds[++de]=a[i];
			*p=a[i];
			*q=a[i];
			ma=max(ma,(int)((p-lis)+(q-lds)-1));
		}
		cout<<ma<<endl;
	}
	return 0;
}

