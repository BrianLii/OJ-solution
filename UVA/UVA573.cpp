#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h;
	double u,d,f;
	while(cin>>h>>u>>d>>f)
	{
		if(!h)return 0;
		f/=100;
		double now=0,up=u;
		for(int i=1;;i++)
		{
			now+=up;
			if(now>h)
			{
				cout<<"success on day "<<i<<'\n';
				break;	
			}
			now-=d;
			if(now<0)
			{
				cout<<"failure on day "<<i<<'\n';
				break;	
			}
			up-=u*f;
			up=max(0.0,up);
		}
	}
	return 0;
}

