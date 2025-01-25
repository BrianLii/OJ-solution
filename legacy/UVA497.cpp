#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int a[200030];
int dp[200030];
int le[200030];
void rec(int x)
{
	if(x==-1)return;
	for(int i=x-1;i>=0;i--)
	{
		if(a[i]==le[x])
		{
			rec(i);
			break;
		}
	}
	cout<<a[x]<<endl;
	return;
}
int toint(string s)
{
	int ans=0;
	for(char i:s)
	{
		ans+=i-'0';
		ans*=10;	
	}
	return ans/10;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	string tra;
	getline(cin,tra);
	getline(cin,tra);
	while(T--)
	{
		string s;
		int n=0;
		while(getline(cin,s))
		{
			if(s=="")break;
			a[n]=toint(s);
			n++;
		}
		memset(dp,0,sizeof(dp));
		memset(le,0,sizeof(le));
		int ans=1;
		dp[1]=a[0];
		dp[0]=-1;
		for(int i=1;i<n;i++)
		{
			if(a[i]>dp[ans])
			{
				dp[++ans]=a[i];
				le[i]=dp[ans-1];	
			}
			else 
			{
				int *p=lower_bound(dp+1,dp+ans+1,a[i]);
				*p=a[i];	
				le[i]=*(p-1);
			}
		}
		cout<<"Max hits: "<<ans<<endl;
		for(int i=n-1;i>=0;i--)
		{
			if(dp[ans]==a[i])
			{
				rec(i);
				break;
			}
		}
		if(T)cout<<endl;
	}
	return 0;
}

