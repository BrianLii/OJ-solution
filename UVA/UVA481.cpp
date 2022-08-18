#include<bits/stdc++.h>
using namespace std;
int a[510000];
int dp[510000];//dp[len] = minimal tail
int pos[510000];//pos[len] = last;
vector<int> ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n=0;
	while(cin>>a[n++]);
	n--;
	dp[1]=a[0];
	int malen=1;
	pos[0]=1;
	for(int i=1;i<n;i++)
	{
		if(a[i]>dp[malen])
		{
			dp[++malen]=a[i];	
			pos[i]=malen;
		}
		else
		{
			int *p = lower_bound(dp+1,dp+malen,a[i]);
			*p=a[i];
			pos[i]=p-dp;
		}
	}
	cout<<malen<<'\n'<<'-'<<'\n';
	stack<int> stk;
	for(int i=n-1;i>=0;i--)
	{
		if(pos[i]==malen)
		{
			stk.push(a[i]); 
			malen--;	
		}
	}
	while(!stk.empty())
	{
		cout<<stk.top()<<endl;
		stk.pop();
	}
	return 0;
}

