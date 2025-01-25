#include<bits/stdc++.h>
using namespace std;
string roatex(int d,string s)
{
	string ans=s;
	while(d--)
	{
		ans[3]=s[0];
		ans[5]=s[3];
		ans[2]=s[5];
		ans[0]=s[2];
		ans[1]=s[1];
		ans[4]=s[4];
		s=ans;
	}
	return ans;
}
string roatey(int d,string s)
{
	string ans=s;
	while(d--)
	{
		ans[4]=s[0];
		ans[0]=s[1];
		ans[1]=s[5];
		ans[5]=s[4];
		ans[2]=s[2];
		ans[3]=s[3];
		s=ans;
	}
	return ans;
}
string roatez(int d,string s)
{
	string ans=s;
	while(d--)
	{
		ans[1]=s[3];
		ans[2]=s[1];
		ans[4]=s[2];
		ans[3]=s[4];
		ans[5]=s[5];
		ans[0]=s[0];
		s=ans;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	while(cin>>in)
	{
		string s1=in.substr(0,6);
		string s2=in.substr(6,6);
		bool suss=0;
		for(int x=0;x<=3&&!suss;x++)
			for(int y=0;y<=3&&!suss;y++)
				for(int z=0;z<=3&&!suss;z++)
				{
					if(roatex(x,roatey(y,roatez(z,s2)))==s1)
					{
						suss=1;
					}
				}
		if(suss)cout<<"TRUE"<<endl;
		else cout<<"FALSE"<<endl;
	}
	return 0;
}

