#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
string add(string &l,string &r)
{
	string ans;
	int car=0;
	for(int i=0;i<l.size()||i<r.size();i++)
	{
		int tmp=car;
		if(i<l.size())tmp+=(l[i]-'0');
		if(i<r.size())tmp+=(r[i]-'0');
		ans+=tmp%10+'0';
		car=tmp/10;
	}
	if(car)ans+=car+'0';
	return ans;
}
string tostring(int x)
{
	string s;
	while(x)
	{
		s.push_back(x%10+'0');
		x/=10;
	}
	return s;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string l="1",r;
	for(int i=1;i<=1000;i++)
	{
		r=tostring(i);
		string ans;
		for(int i=0;i<r.size();i++)
		{
			string now;
			for(int j=0;j<i;j++)now+='0';
			int car=0;
			for(int j=0;j<l.size();j++)
			{
				int tmp=car+(r[i]-'0')*(l[j]-'0');
				now+=(tmp%10+'0');
				car=tmp/10;
			}
			if(car)now+=car+'0';
			ans=add(ans,now);		
		}
		//reverse(ans.begin(),ans.end());
		l=ans;
	}
	reverse(l.begin(),l.end());
	cout<<l<<endl;
	return 0;
}

