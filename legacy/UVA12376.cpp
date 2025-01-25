#include<bits/stdc++.h>
using namespace std;
int d[200];
vector<int>edge[200];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int ct=1;ct<=t;ct++)
	{
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n+1;i++)edge[i].clear();
		for(int i=0;i<n;i++)cin>>d[i];
		while(m--)
		{
			int ta,tb;
			cin>>ta>>tb;
			edge[ta].push_back(tb);
		}
		int now=0;
		int sum=0;
		while(!edge[now].empty())
		{
			int mi=INT_MIN,num=-1;
			for(int i:edge[now])
			{
				if(d[i]>mi)
				{
					mi=d[i];
					num=i;
				}
			}
			sum+=d[num];
			now=num;
		}
		cout<<"Case "<<ct<<": ";
		cout<<sum<<' '<<now<<endl;
	}
		
	return 0;
}

