#include<bits/stdc++.h>
using namespace std;
int toint(string &s)
{
	int ans=0;
	for(char i:s)
	{
		if(i<='9'&&i>='0')ans=ans*16+i-'0';
		else ans=ans*16+i-'A'+10;
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
		char op;
		cin>>s1>>op>>s2;
		int l=toint(s1),r=toint(s2);
		for(int i=12;i>=0;i--)
		{
			cout<<bool(l&(1<<i));
		}
		cout<<' '<<op<<' ';
		for(int i=12;i>=0;i--)
		{
			cout<<bool(r&(1<<i));
		}
		cout<<" = ";
		if(op=='+')cout<<l+r<<endl;
		else cout<<l-r<<endl;
	}
	return 0;
}

