#include<bits/stdc++.h>
using namespace std;
int a[25],dp[25][500],use[25][500];
int cnt=1;
bool dfs(int l,int sum)
{
	if(use[l][sum]==cnt)return dp[l][sum];
	if(sum<0)return dp[l][sum]=0;
	use[l][sum]=cnt;
	if(sum==0)return dp[l][sum]=1;
	if(l==0)
	{
		if(sum==0)return dp[l][sum]=1;
		else return dp[l][sum]=0;
	}
	return dp[l][sum]=dfs(l-1,sum-a[l])||dfs(l-1,sum);
}
int main()
{
	int n,sum=0;
	int t;
	string te;
	cin>>t;
	getline(cin,te);
	while(t--){
		string s;
		getline(cin,s);
		stringstream ss;
		ss.str("");
		ss.clear();
		ss<<s;
		int i=0;
		while(ss>>a[++i])sum+=a[i];
		//for(int j=1;j<i;j++)cout<<a[j]<<' ';
		cout<<(dfs(i-1,sum/2)&&!(sum&1)?"YES":"NO")<<endl;
		cnt++;
		sum=0;
	}
	return 0;
}

