#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
int ans[10020];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,t,m;
		cin>>n>>t>>m;
		queue<pii> Q[2];
		for(int i=0;i<m;i++)
		{
			ans[i]=0;
			int tmp;
			cin>>tmp;
			string s;
			cin>>s;
			if(s=="left")Q[0].emplace(tmp,i);
			else Q[1].emplace(tmp,i);
		}
		Q[0].emplace(INT_MAX,m+10);
		Q[1].emplace(INT_MAX,m+11);
		bool now=0;
		int nt=0;
		int load=0;
		while(Q[0].size()>=2||Q[1].size()>=2)
		{
			while(load<n&&Q[now].front().X<=nt)
			{
				load++;
				ans[Q[now].front().second]=nt+t;
				Q[now].pop();
			}
			if(load||Q[now^1].front().X<=nt)
			{
				load=0;
				nt+=t;
				now^=1;
			}
			else
			{
				int mi=INT_MAX;
				mi=min(Q[0].front().X,mi);
				mi=min(Q[1].front().X,mi);
				nt=mi;
			}
		}
		for(int i=0;i<m;i++)cout<<ans[i]<<endl;
		if(T)cout<<endl;
	}
	return 0;
}

