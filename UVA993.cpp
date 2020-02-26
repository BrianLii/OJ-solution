#include<bits/stdc++.h>
using namespace std;
int jie[10];
inline int add(int x,int y)
{
	for(int i=10;;i*=10)
		if(i>y)
		{
			cout<<x*i+y<<endl;
			return x*i+y;	
		}
}
int rec(int x)
{
	if(x==0||x==1)return x;
	//cout<<x<<endl;
	int mi=INT_MAX;
	int num=-1;
	for(int i=2;i<=9;i++)
	{
		if(x==i)return i;
		if(x%i==0)
		{
			int tmp=rec(x/i);
			if(add(i,tmp)>mi)
			{
				num=i;
				mi=tmp;
			}
		}
	}
	if(mi==INT_MAX)return INT_MAX; 
	for(int i=10;;i*=10)
		if(i>mi)return num*i+mi;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	jie[0]=1;
	for(int i=1;i<10;i++)jie[i]=10*jie[i-1];
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<10)
		{
			cout<<n<<endl;
			continue;	
		} 
		int cnt=0;
		int ans=0;
		for(int i=9;i>=2;i--)
		{
			while(n%i==0)
			{
				ans+=jie[cnt++]*i;
				n/=i;
			}
		}
		if(n!=1)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}

