#include<bits/stdc++.h>
using namespace std;
int dx[]{1,1,-1,-1};
int dy[]{1,-1,1,-1};
int x,y;
int dfs(int px,int py,int k)
{
	if(k==0)return 0;
	int i;
	if(x<=px&&y<=py)i=3;
	else if(x>px&&y<=py)i=1;
	else if(x<=px&&y>py)i=2;
	else i=0;
	int ans=dfs(px+k*dx[i],py+k*dy[i],k/2);
	if(x<=px+k&&x>=px-k&&y<=py+k&&y>=py-k)ans++;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	while(cin>>k>>x>>y)
	{
		if(!k&&!x&&!y)return 0;
		cout<<setw(3)<<dfs(1024,1024,k)<<endl;
		
	}
	return 0;
}

