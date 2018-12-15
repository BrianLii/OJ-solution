#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int n,a[300];
bool ok(int x)
{
	if(abs(n-x-x)<=1)return 1;
	else return 0;
}
int cnt;
int dfs(int l,int w,int p)
{
	//cout<<l<<' '<<w<<' '<<p<<' '<<endl;
	if(w<0)return -INF;
	if(l==0)
	{
		if(!ok(p))return -INF;
		if(w>=a[l]&&ok(p+1))return a[l];
		else return 0;
	}
	return max(dfs(l-1,w-a[l],p+1)+a[l],dfs(l-1,w,p));
}
//int dp[30][7000][30];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		//cout<<dfs(n-1,sum/2,0);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
			}
		}
	}
	return 0;
}

