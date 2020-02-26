#include<bits/stdc++.h>
#define endl '\n'
#define double long double
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
struct node
{
	char c;
	double val[6]={0};
};
int conv(char c)
{
	if(c=='r')return 4;
	else if(c=='c')return 3;
	else return 6 ;
}
double cross(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}
bool in(node &now,double x,double y)
{
	if(now.c=='r')
	{
		return(x>now.val[0]&&x<now.val[2]&&y<now.val[1]&&y>now.val[3]);
	}
	else if(now.c=='c') 
	{
		return (x-now.val[0])*(x-now.val[0])+(y-now.val[1])*(y-now.val[1])<now.val[2]*now.val[2];
	}	
	else
	{
		if(cross(x-now.val[0],y-now.val[1],now.val[2]-now.val[0],now.val[3]-now.val[1])*
		   cross(x-now.val[0],y-now.val[1],now.val[4]-now.val[0],now.val[5]-now.val[1])>=0)return 0;
		   
		if(cross(x-now.val[2],y-now.val[3],now.val[0]-now.val[2],now.val[1]-now.val[3])*
		   cross(x-now.val[2],y-now.val[3],now.val[4]-now.val[2],now.val[5]-now.val[3])>=0)return 0;
		   	
		if(cross(x-now.val[4],y-now.val[5],now.val[2]-now.val[4],now.val[3]-now.val[5])*
		   cross(x-now.val[4],y-now.val[5],now.val[0]-now.val[4],now.val[1]-now.val[5])>=0)return 0;
		   
		return 1;
	}
}
vector<node> v;
signed main()



{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c;
	while(cin>>c)
	{
		if(c=='*')break;
		v.emplace_back(node());		
		for(int i=0,len=conv(c);i<len;i++)cin>>v.back().val[i];
		v.back().c=c;
	}
	double x,y;
	int C=0;
	while(cin>>x>>y)
	{
		if(abs(x-9999.9)<1e-8&&abs(y-9999.9)<1e-8)break;
		C++;
		bool flag=0;
		for(int i=0;i<v.size();i++)
		{
			if(in(v[i],x,y))
			{
				cout<<"Point "<<C<<" is contained in figure "<<i+1<<endl;
				flag=1;
			}
		}
		if(!flag)cout<<"Point "<<C<<" is not contained in any figure"<<endl;
	}
	return 0;
}
