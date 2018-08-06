#include<bits/stdc++.h>
using namespace std;
vector<int> a; 
int s[10030];
pair<int,int> dp[10030];//<max(n),last one picked>
int main()
{
	int n,tmp;
	cin>>n;
	while(n)
	{
		cin>>tmp;
		if(tmp>0)
		{
			a.push_back(tmp);
			break;
		}
		n--;
		cout<<n<<' ';
	}
	if(a.empty())
	{
		cout<<"Losing streak."<<endl;
		return 0; 
	}
	else s[0]=a[0];
	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		s[i]=s[i-1]+tmp;
		a.push_back(tmp);
	}
	dp[0]=make_pair(a[0],0);
	for(int i=1;i<n;i++)
	{
		int pick=dp[i-1].first+(s[i]-s[dp[i-1].second]);
		int notpick=dp[i-1].first;
		if(pick>notpick)dp[i]=make_pair(pick,i);
		else dp[i]=make_pair(notpick,dp[i-1].second);
	}
	cout<<dp[n-1].first<<endl;
}

