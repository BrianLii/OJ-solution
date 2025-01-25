#include<bits/stdc++.h>
using namespace std;
vector<int>edge[200];
int n,k;
int vis[200];
int clr[200];
int cnt;
int dfs(int now,bool c)
{
	vis[now]=1;
	clr[now]=c;
	cnt+=c;
	int ans=1;
	for(int i:edge[now])
	{
		if(!vis[i])
		{
			ans+=dfs(i,!c);
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<=n;i++)
		{
			edge[i].clear();
			vis[i]=0;
		}
		while(k--)
		{
			int ta,tb;
			cin>>ta>>tb;
			edge[ta].push_back(tb);	
			edge[tb].push_back(ta);	
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				int r=dfs(i,1);
				cout<<"r : "<<r<<endl;
				ans+=max(r-cnt,cnt);
				cnt=0;
			}
		}
		cout<<ans<<endl;
		//cout<<cnt<<endl;
		//cout<<max(n-cnt,cnt)<<endl;	
	}
	return 0;
}
/*
3
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6

2 0

6 5
1 2
1 3
2 3
4 5
4 6
*/
