#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct fib 
{
	int a[250]={0};
};
void operator << (fib &a,string &s)
{
	auto it=s.begin();
	for(int i=0;i<s.size();i++)
	{
		
		a.a[i]=(*it)-'0';
		it++;
	}
	
}
fib operator + (fib a,fib b)
{
	fib ans;
	for(int i=0,c=0;i<=203;i++)
	{
		ans.a[i]=a.a[i]+b.a[i]+c;
		c=ans.a[i]/10;
		ans.a[i]%=10;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		fib x,y;
		cin>>s1>>s2;
		x<<s1;
		y<<s2;
		fib c;
		c=x+y;
		int sta=0;
		while(c.a[sta]==0)sta++;
		string tmp;
		for(int i=sta;i<=203;i++)
		{
			//cout<<c.a[i];
			if(c.a[i]==0)tmp+='0';
			else 
			{
				cout<<tmp<<c.a[i];
				tmp.clear();	
			}
		}
		cout<<endl;
		//if(t)cout<<endl; 
	}
	return 0;
}

