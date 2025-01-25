#include<bits/stdc++.h>
using namespace std;
int a[20];
int t,n;
vector<int> ans;
bool suss=0;
void dfs(int now,int left)
{
	if(left==0)
	{
		suss=1;
		for(int i=0;i<ans.size();i++)
		{
			if(i)cout<<"+";
			cout<<ans[i];
		}
		cout<<endl;
		return ;
	}
	if(now==n)return;
	if(left>=a[now])
	{
		ans.push_back(a[now]);
		dfs(now+1,left-a[now]);
		ans.pop_back();
	}
	while(now+1<n&&a[now+1]==a[now])now++;
	dfs(now+1,left);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>t>>n)
	{
		suss=0;
		if(!t&&!n)break;
		cout<<"Sums of "<<t<<":"<<endl;
		for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n,greater<int>());
		dfs(0,t);
		
		if(!suss)cout<<"NONE"<<endl;
	}
	return 0;
}

