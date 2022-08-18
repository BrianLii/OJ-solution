#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a[50];
int dp[25][1020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int p;
		cin>>p;
		if(p==1)
		{
			int x;
			cin>>x;
			cout<<"party 1 has power index 1"<<endl;
			cout<<endl;
			continue;
		}
		else if (p==2)
		{
			int x,y;
			cin>>x>>y;
			int ans=0;
			if(x>(x+y)/2)ans++;
			if(y<=(x+y)/2)ans++;
			cout<<"party 1 has power index "<<ans<<endl;
			swap(x,y);
			ans=0;
			if(x>(x+y)/2)ans++;
			if(y<=(x+y)/2)ans++;
			cout<<"party 2 has power index "<<ans<<endl;
			cout<<endl;
			continue;
		}
		int sum=0;
		for(int i=0;i<p;i++)
		{
			cin>>a[i];		
			sum+=a[i];
		}
		for(int idx=0;idx<p;idx++)
		{
			swap(a[idx],a[p-1]);
			memset(dp,0,sizeof(dp));
			int l=sum/2-a[p-1]+1;
			int r=sum/2;
			dp[0][a[0]]=1;
			dp[0][0]=1;
			for(int i=1;i<=p-2;i++)
			{
				for(int j=0;j<=1000;j++)
				{
					if(j<a[i])dp[i][j]=dp[i-1][j];
					else dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
				}
			}
			int ans=0;
			for(int i=l;i<=r;i++)
			{
				ans+=dp[p-2][i];
			}
			cout<<"party "<<idx+1<<" has power index "; 
			cout<<ans<<endl;
			swap(a[idx],a[p-1]);
		}
		cout<<endl;
	}
	return 0;
}

