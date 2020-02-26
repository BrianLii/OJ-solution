#include<bits/stdc++.h>
using namespace std;
long long toint(string &s)
{
	stringstream ss;
	ss<<s;
	long long ans=0;
	ss>>ans;
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string l,r;
	char c;
	string tl,tr;
	string inin;
	while(getline(cin,inin))
	{
		cout<<inin<<endl;
		stringstream ss;
		ss<<inin;
		ss>>tl>>c>>tr;
		l="";
		r="";
		bool flag=0;
		for(char c:tl)
		{
			if(flag)l+=c;
			else if(c!='0')
			{
				l+=c;
				flag=1;
			}
		}
		if(!l.size())l="0";
		flag=0;
		for(char c:tr)
		{
			if(flag)r+=c;
			else if(c!='0')
			{
				r+=c;
				flag=1;
			}
		}
		if(!r.size())r="0";
		if(l.size()>=11||toint(l)>INT_MAX)
			cout<<"first number too big"<<endl;
		if(r.size()>=11||toint(r)>INT_MAX)
			cout<<"second number too big"<<endl;
		if((l.size()>=11||toint(l)>INT_MAX||
		   r.size()>=11||toint(r)>INT_MAX)&&l!="0"&&r!="0")
		   	cout<<"result too big"<<endl;
		else
		{
			long long a=toint(l),b=toint(r),ans;
			if(c=='+')ans=a+b;
			else ans=a*b;
			if(ans>INT_MAX)cout<<"result too big"<<endl;
		}
	}
	return 0;
}

