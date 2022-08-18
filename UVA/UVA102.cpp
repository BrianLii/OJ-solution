#include<bits/stdc++.h>
#define G 0
#define B 1
#define C 2
#define pb push_back
#define popb pop_back 
typedef long long ll;
ll a[5][5],sum[5];
using namespace std;
vector<int> p,ans;
int cnt=1;
int visit[5];
ll mi=0xfffffffffffffffLL;
void count()
{
	ll tmp=0;
	for(int i=0;i<3;i++)
	{
		tmp+=sum[i]-a[i][p[i]];
	}
	if(tmp<mi)
	{
		mi=tmp;
		ans=p;
	}
}
void dfs(int x)
{
	if(x==3)
	{
		count();
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(visit[i]!=cnt)
		{
			visit[i]=cnt;
			p.pb(i);
			dfs(x+1);
			p.popb();
			visit[i]=-1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>a[0][0])
	{
		cnt++;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(i!=0||j!=0)cin>>a[i][j];
				sum[i]+=a[i][j];
			}
			swap(a[i][1],a[i][2]);
		}
		dfs(0);
		for(int i:ans)
		{
			if(i==0)cout<<'B';
			else if(i==1)cout<<'C';
			else cout<<'G';
		}
		cout<<' '<<mi<<'\n';
		mi=0xfffffffffffffffLL;
		ans.clear();
		p.clear();
		//memset(visit,0,sizeof(visit));
		//memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
	}
	
	return 0;
}

