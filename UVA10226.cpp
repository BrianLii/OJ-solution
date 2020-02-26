#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<fixed<<setprecision(4);
	int T;
	cin>>T;
	string tra;
	getline(cin,tra);
	getline(cin,tra);
	while(T--)
	{
		string s;
		int n=0;
		map<string,int> mp;
		while(getline(cin,s))
		{
			if(s=="")break;
			n++;
			mp[s]++;
		}
		for(auto &i:mp)
		{
			cout<<i.first<<' '<<(100.0*i.second)/n<<endl;
		}
		if(T)cout<<endl;
	}
	return 0;
}
/*
pA. 57C / 1900
pB. 518E / 2400
pC. 63C / 1800
pD. 118D / 1800
pE. 349A / 1200
pF. 80B / 1200
pG. 780D / 2000
pH. 453C / 2800
pI. 255D / 1900
pJ. 898F / 2300
pK. 141D / 2400
pL. 136B / 1200
pM. 301A / 1800
*/
