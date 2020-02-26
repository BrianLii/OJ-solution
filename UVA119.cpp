#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
unordered_map<string,int> mp;
vecto
int conv(string s)
{
	if(mp.count(s)==0)
	{
		int tmp=mp.size();
		mp[s]=tmp;
		return tmp;
	}
	else return mp[s];
}
int val[100000];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		conv(s);
	}
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int tmp=conv(s);
		int a,b;
		cin>>a>>b;
		val[tmp]-=a;
		for(int j=0;j<b;j++)
		{
			cin>>s;
			val[conv(s)]+=(a/b);
		}
	}
	for(int i=0;i<n;i++)cout<<val[i]<<endl;
	return 0;
}

