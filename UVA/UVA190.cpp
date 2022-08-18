#include<bits/stdc++.h>
using namespace std;
double del(double a,double b,double c,double d)
{
	return a*d-b*c;
}
void solve(double a1,double b1,double c1,double a2,double b2,double c2,double &x,double &y)
{
	double d=del(a1,b1,a2,b2);
	double dx=del(c1,b1,c2,b2);
	double dy=del(a1,c1,a2,c2);
	x=dx/d;
	y=dy/d;
}
double dis(double x1,double y1,double x2,double y2)
{
	return((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void out(double x)
{
	if(x<0)cout<<"- "<<-x;
	else cout<<"+ "<<x;
}
void out2(double x,char c)
{
	if(abs(x)<0.0000001)return;
	cout<<' ';
	out(x);
	cout<<c;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(3);
	double x1,y1;
	double x2,y2;
	double x3,y3;
	while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
	{
		double anst=0,ansT=0;
		solve(y2-y1,y2-y3,(x3-x1)/2.0,
		      x1-x2,x3-x2,(y3-y1)/2.0,anst,ansT);
		double ansx=(x1+x2)/2.0+anst*(y2-y1);
		double ansy=(y1+y2)/2.0+anst*(x1-x2);
		double r2=dis(ansx,ansy,x1,y1);
		if(abs(ansx)<0.0000001)cout<<"x^2";
		else 
		{
			cout<<"(x";
			cout<<' ';
			out(-ansx);
			cout<<')';
			cout<<"^2";
		}
		cout<<" + ";
		if(abs(ansy)<0.0000001)cout<<"y^2";
		else 
		{
			cout<<"(y";
			cout<<' ';
			out(-ansy);
			cout<<')' ;
			cout<<"^2";
		}
		cout<<" = "<<sqrt(r2)<<"^2";
		cout<<endl;
		cout<<"x^2 + y^2";
		out2((-2)*ansx,'x');
		out2((-2)*ansy,'y');
		cout<<' ';
		out(ansx*ansx+ansy*ansy-r2);
		cout<<" = "<<0<<endl<<endl; 
	}
	return 0;
}

