#include<bits/stdc++.h>
using namespace std;
int n,k;
typedef pair<int,int> pii;
long long a[200020][15];
long long tenpow[15];
map<pair<int,int>,int> mp;
int main()
{
	cin>>n>>k;
	tenpow[0]=1;
	for(int i=1;i<=10;i++)tenpow[i]=tenpow[i-1]*10;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0];
		int x=0;
		int tmp=a[i][0];
		while(tmp)
		{
			tmp/=10;
			x++;
		}
		a[i][0]%=k;
		mp[pii(a[i][0],x)]++;
		for(int j=1;j<=10;j++)
		{
			a[i][j]=a[i][j-1]*10%k;
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=10;j++)
		{
			cout<<i<<' '<<j<<' '<<mp[pii((k-a[i][j])%k,j)]<<endl;
			ans+=mp[pii((k-a[i][j])%k,j)];
		}
	}
	return 0;
}

