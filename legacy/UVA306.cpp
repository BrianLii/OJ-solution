#include<bits/stdc++.h>
using namespace std;
int a[220]; 
int use[220];
int k;
int cal(int i)
{
	memset(use,0,sizeof(use));
	int now=i;
	use[now]=1;
	int cnt=1;
	while(1)
	{
		now=a[now];
		if(use[now])break;
		use[now]=1;
		cnt++;
	}
	now=i;
	for(int j=0;j<k%cnt;j++)
	{
		now=a[now];
	}
	return now;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		if(!n)break;
		for(int i=1;i<=n;i++)cin>>a[i];
		while(cin>>k)
		{
			if(!k)
			{
				cout<<endl;
				break;	
			}
			string now,next;
			getline(cin,now);
			while(now.size()<=n)now+=' ';
			next=now;
			for(int i=1;i<=n;i++)
			{
				next[cal(i)]=now[i];
			}
			for(int i=1;i<next.size();i++)
			{
				cout<<next[i];
			}
			cout<<endl;
		}
	}
	return 0;
}

