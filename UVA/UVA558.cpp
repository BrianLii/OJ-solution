#include<bits/stdc++.h>
#define INF INT_MAX 
using namespace std;
typedef pair<int,int> pii;
vector<pii> edge[1100];
int dis[1100];
bool inq[1100];
int in[1100];
int n;
bool SPFA(int s)
{
	for(int i=0;i<=n;i++)dis[i]=INF;
	memset(in,0,sizeof(in));
	memset(inq,0,sizeof(inq));
	queue<int> q;
	q.push(s);
	inq[s]=1;
	dis[s]=0;
	while(!q.empty())
	{
		int now=q.front();
		inq[now]=0;
		q.pop();
		for(auto i:edge[now])
		{
			if(dis[i.first]>dis[now]+i.second)
			{
				dis[i.first]=dis[now]+i.second;
				if(!inq[i.first])
				{
					q.push(i.first);
					inq[i.first]=1;
					in[i.first]++;
					if(in[i.first]>=n)return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int m;
		cin>>n>>m;
		for(int i=0;i<=n;i++)edge[i].clear();
		while(m--)
		{
			int a,b,w;
			cin>>a>>b>>w;
			edge[a].push_back(pii(b,w));
		}
		cout<<(SPFA(0)?"possible":"not possible")<<endl;
	}
	return 0;
}

