#include<bits/stdc++.h>
using namespace std;
const int shift=5;
struct big
{
	int s[450]={0};
};
big operator+(big _a,big _b)
{
	big ans;
	for(int i=0,tmp=0;i<=410;i++)
	{
		ans.s[i]=(_a.s[i]+_b.s[i]+tmp)%10;
		tmp=(_a.s[i]+_b.s[i]+tmp)/10;
	}
	return ans;
}
big dp[1030];
int n;
void solve()
{
	dp[0+shift].s[0]=1;
	for(int i=1;i<=1010;i++)
	{
		dp[i+shift]=
		dp[i-1+shift]+
		dp[i-1+shift]+
		dp[i-2+shift]+
		dp[i-3+shift];
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	while(cin>>n)
	{
		big ans=dp[n+shift];
		for(int i=420,ctr=0;i>=0;i--)
		{
			ctr|=ans.s[i];
			if(ctr)
			{
				cout<<ans.s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}

