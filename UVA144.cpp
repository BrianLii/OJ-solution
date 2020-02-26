#include<bits/stdc++.h>
using namespace std;
int take[30];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	while(cin>>n>>k)
	{
		if(!n&&!k)break;
		queue<int>  q;
		for(int i=0;i<=n;i++)take[i]=0;
		for(int i=1;i<=n;i++)
		q.push(i);
		int cnt=0,left=0;
		while(!q.empty())
		{
			int now=q.front();
			q.pop();
			if(left==0)
			{
				left=cnt%k+1;
				cnt++;
			}
			if(left>=40-take[now])
			{
				left-=(40-take[now]);
				cout<<setw(3)<<now;
			}
			else
			{
				take[now]+=left;
				q.push(now);
				left=0;
			}
		}
		cout<<'\n'; 
	}
	
	return 0;
}

