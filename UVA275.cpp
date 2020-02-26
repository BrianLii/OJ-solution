#include<bits/stdc++.h>
using namespace std;
int use[12000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b)
	{
		int out=1;
		memset(use,0,sizeof(use));
		if(!a&&!b)return 0;
		int now=a;
		now*=10;
		int cnt=1;
		cout<<'.';
		while(1)
		{
			use[now]=cnt++;
			if(out+1>50)
			{
				cout<<endl;
				out=0;	
			}
			cout<<now/b;
			out++;
			now%=b;
			if(now==0)
			{
				cout<<endl<<"This expansion terminates."<<endl; 
				break;
			}
			now*=10;
			if(use[now])
			{
				cout<<endl<<"The last "<<cnt-use[now]<<" digits repeat forever."<<endl;
				break;	
			}
		}
		cout<<endl;
	}
	return 0;
}

