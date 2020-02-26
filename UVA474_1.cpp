#include<bits/stdc++.h>
using namespace std;
double log10(int x)
{
	return log(x)/log(10);
}
double ans[1000020];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	n=1000000;
	double now=1;
	for(int i=1;i<=n;i++)
	{
		now*=10;
		if(now>1e10)now/=10;
		now/=2;
		while(now>=10)now/=10;
		ans[i]=now;
	}
	while(cin>>n)
	{
		cout<<fixed<<setprecision(3);
		cout<<"2^-"<<n<<" = "<<ans[n]<<"e";
		cout<<int(-1*n*log10(2))-1<<endl;
	}
	return 0;
}

