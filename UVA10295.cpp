#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
unordered_map<string,int>mp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n;
	cin>>m>>n;
	while(m--)
	{
		string s;
		int t;
		cin>>s>>t;
		mp[s]=t;
	}
	string s;
	while(cin>>s)
	{
		int ans=0;
		while(s!=".")
		{
			ans+=mp[s];
			cin>>s;
		}
		cout<<ans<<endl;
	}
	return 0;
}

