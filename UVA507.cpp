#include<bits/stdc++.h>
using namespace std;
int a[200020];
int fa[200020];
int dp[200020];
int cal(int x,int y)
{
	if(x==-1)return 1;
	else return y-x+1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		memset(dp,0,sizeof(dp));
		memset(fa,0,sizeof(fa));
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		n--;
		for(int i=0;i<n;i++)cin>>a[i];
		dp[0]=a[0];
		int ma=0,len=0,num=-1;
		fa[0]=-1;
		if(dp[0]>0)
		{
			ma=dp[0];
			len=1;
			num=0;
		}
		for(int i=1;i<n;i++)
		{
			if(dp[i-1]>=0)
			{
				dp[i]=dp[i-1]+a[i];
				if(~fa[i-1])fa[i]=fa[i-1];
				else fa[i]=i-1;
			}
			else
			{
				dp[i]=a[i];
				fa[i]=-1;
			}
			if(dp[i]>ma||(dp[i]==ma&&len<cal(fa[i],i)))
			{
				ma=dp[i];
				num=i;
				len=cal(fa[i],i);
			}
		}
		++cnt;
		if(!ma)cout<<"Route "<<cnt<<" has no nice parts"<<endl;
		else cout<<"The nicest part of route "<<cnt<<" is between stops "
		         <<num-len+2<<" and "<<num+2<<endl;
	}
	return 0;
}

