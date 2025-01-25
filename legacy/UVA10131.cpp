#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
struct node
{
	int w,num,iq;
};
bool operator < (node &_a,node &_b)
{
	return _a.iq==_b.iq?_a.w>_b.w:_a.iq>_b.iq;
}
node a[1100];
int dp[1100];
int pos[1100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0;
	while(cin>>a[cnt].w>>a[cnt].iq)
	{
		a[cnt].num=cnt;
		cnt++;
	}
	sort(a,a+cnt);
	dp[1]=a[0].w;
	int len=1;
	pos[0]=1;
	for(int i=1;i<cnt;i++)
	{
		if(a[i].w>dp[len])
		{
			++len;
			dp[len]=a[i].w;
			pos[i]=len;
		}
		else 
		{
			int *p=lower_bound(dp+1,dp+len+1,a[i].w);
			*p=a[i].w;
			pos[i]=p-dp;	
		}
	}
	cout<<len<<endl;
	stack<int> stk;
	for(int i=cnt-1;i>=0&&len;i--)
	{
		if(pos[i]==len)
		{
			len--;
			stk.push(a[i].num);
		}
	}
	while(stk.size())
	{
		cout<<stk.top()+1<<endl;
		stk.pop();
	}
	return 0;
}

