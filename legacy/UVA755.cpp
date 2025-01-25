#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
map<string,int> mp;
inline int conv(char c)
{
	if(c=='A'||c=='B'||c=='C')return 2;
	if(c=='D'||c=='E'||c=='F')return 3;
	if(c=='G'||c=='H'||c=='I')return 4;
	if(c=='J'||c=='K'||c=='L')return 5;
	if(c=='M'||c=='N'||c=='O')return 6;
	if(c=='P'||c=='R'||c=='S')return 7;
	if(c=='T'||c=='U'||c=='V')return 8;
	if(c=='W'||c=='X'||c=='Y')return 9;
	return -1;
}
void out(string s)
{
	int i;
	for(i=0;i<=2;i++)cout<<s[i];
	cout<<'-';
	for(;i<7;i++)cout<<s[i];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		mp.clear();
		while(n--)
		{
			string s;
			cin>>s;
			string now;
			for(char c:s)
			{
				if(c=='-')continue;
				else 
				{
					int t=conv(c);
					if(t==-1)now+=c;
					else now+=(t+'0');	
				}
			}
			mp[now]++;
		}
		int cnt=0;
		for(auto i:mp)
		{
			if(i.second<=1)continue;
			cnt++;
			out(i.first);
			cout<<' '<<i.second<<endl;
		}
		if(!cnt)cout<<"No duplicates."<<endl;
		if(T)cout<<endl;
	}
	return 0;
}

