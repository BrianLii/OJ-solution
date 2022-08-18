#include<bits/stdc++.h>
using namespace std;
bool tree[1<<22];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int D,i;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>D>>i;
		string s;
		int now=1;
		i--;
		for(int j=0;j<D-1;j++)
		{
			if(i&(1<<j))
			{
				now=now*2+1;
			}
			else 
			{
				now=now*2;
			}
		}
		cout<<now<<endl;
		/*for(int i=0;i<(1<<D);i++)tree[i]=0;
		int cnt=0;
		while(i--)
		{
			int now=1;
			for(int dep=1;dep<=D;dep++)
			{
				tree[now]=!tree[now];
				if(tree[now])
				{
					now=now*2;	
					cout<<'L';
				}
				else 
				{
					now=now*2+1;
					cout<<'R';	
				}
			}
			for(int i=0;i<4;i++)cout<<bool(cnt&(1<<i));
			cnt++;
			cout<<endl;
		}*/
	}
	return 0;
}

