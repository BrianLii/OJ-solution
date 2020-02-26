#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
bool check(string s)
{
	for(int i=sz(s)-2;i>=0;i--)
	{
		int l=i,r=sz(s)-1;
		bool fail=0;
		while(!fail)
		{
			if(r<=i)break; 
			if(s[l]!=s[r])fail=1;
			if(l<0)fail=1;
			l--;
			r--;
		}
		if(!fail)return 0;
	}
	return 1;
}
string now;
int L;
vector<string> ans[27];
void dfs()
{
	if(sz(ans[L])>200)return;
	for(int i=0;i<L;i++)
	{
		if(check(now+char(i+'A')))
		{
			now+=(i+'A');
			ans[L].emplace_back(now);
			dfs();
			now.pop_back();
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=26;i++)
	{
		L=i;
		dfs();
	}
	int n;
	while(cin>>n>>L)
	{
		if(!n&&!L)break;
		string &s=ans[L][n-1];
		for(int i=0;i<sz(s);i++)
		{
			if(i!=0&&i%(16*4)==0)cout<<endl;
			else if(i!=0&&i%4==0)cout<<' ';
			cout<<s[i];
		}
		cout<<endl;
		cout<<s.size()<<endl;
	}
	return 0;
}

