#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
using namespace std;
int lead[60];
void init(int x=30)
{
	for(int i=0;i<=x;i++)lead[i]=i;
}
int find(int x)
{
	if(lead[x]==x)return x;
	return lead[x]=find(lead[x]);
}
bool same(int x,int y)
{
	return find(x)==find(y);
}
void U(int x,int y)
{
	lead[find(x)]=find(y);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		char c;
		cin>>c;
		int cnt=c-'A'+1;
		init();
		string s;
		getline(cin,s);
		while(getline(cin,s))
		{
			if(s=="")break;
			int l=s[0]-'A';
			int r=s[1]-'A';
			if(!same(l,r))
			{
				cnt--;
				U(l,r);
			}
		}
		cout<<cnt<<endl;
		if(T)cout<<endl;
	}
	return 0;
}

