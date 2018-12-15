#include<bits/stdc++.h>
using namespace std;
int a[2000];
int sum[4000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt=0;
	while(cin>>n)
	{
		if(!n)return 0;
		cout<<"Case "<<++cnt<<":"<<endl;
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		int l=0;
		for(int i=0;i<n;i++)cin>>a[i];
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				sum[l++]=a[i]+a[j];
			}
		sort(sum,sum+l);
		int m;
		cin>>m;
		while(m--)
		{
			int q;
			cin>>q;
			cout<<"Closest sum to "<<q<<" is ";
			int *p=lower_bound(sum,sum+l,q);
			if(*p==q)cout<<q<<'.'<<endl;
			else 
			{
				if(p-sum)
				{
					if(abs(q-*(p-1))<abs(*p-q))
					{
						cout<<*(p-1);
					} 
					else cout<<*p;
				}
				else cout<<*p;
				cout<<'.'<<endl;
			}
		}
	}
	return 0;
}

