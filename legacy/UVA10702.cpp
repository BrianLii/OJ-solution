#include<bits/stdc++.h>
using namespace std;
long long adj[120][120],p[120],q[120];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int C,S,E,T;
	while(cin>>C>>S>>E>>T)
	{
		if(!C)return 0;
		S--;
		for(int i=0;i<C;i++)
			for(int j=0;j<C;j++)
				cin>>adj[i][j];
		long long *now=p,*last=q;
		for(int i=0;i<C;i++)
		{
			last[i]=adj[S][i];
		}
		T--;
		while(T--)
		{
			for(int i=0;i<C;i++)
			{
				now[i]=-1;
				for(int j=0;j<C;j++)
				{
					if(now[i]<last[j]+adj[j][i])now[i]=last[j]+adj[j][i];
				}	
			}	
			swap(now,last);
		}
		int tmp=0;
		long long MAX=0;
		while(E--)
		{
			cin>>tmp;
			tmp--;
			if(last[tmp]>MAX)MAX=last[tmp];
		}
		cout<<MAX<<endl;
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
	} 
	
	return 0;
}

