#include<bits/stdc++.h>
using namespace std;
string s;
bool check(int l,int r)
{
	for(int i=l,j=r;i<j;i++,j--)
	{
		if(s[i]!=s[j])return 0;
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s)
	{
		int cnt=0;
		set<string> se;
		for(int i=0,last=-1;i<s.size();i++)
		{
			if(cnt>=2)break;
			for(int j=last<i?i+2:last+1;j<s.size();j++)
			{
				if(check(i,j)&&se.find(s.substr(i,j-i+1))==se.end())
				{
					cout<<s.substr(i,j-i+1)<<endl;
					se.insert(s.substr(i,j-i+1));
					last=j;
					cnt++;
					break;
				}
			}		
		} 
		if(cnt>=2)cout<<s<<'\n';
	}
	return 0;
}

