#include<bits/stdc++.h>
using namespace std;
int in[120];
vector<int> edge[120];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	while(cin>>n>>m)
	{
		if(!n&&!m)return 0;
		memset(in,0,sizeof(in));
		for(int i=0;i<=n;i++)edge[i].clear();
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			in[b]++;
		}
		queue<int> q;
		for(int i=1;i<=n;i++)
		{
			if(!in[i])q.push(i);	
		}
		while(!q.empty())
		{
			int now=q.front();
			cout<<now<<' ';
			q.pop();
			for(int i:edge[now])
			{
				in[i]--;
				if(in[i]==0)
					q.push(i);
			}
		}
		cout<<endl;
	}
	return 0;
}

