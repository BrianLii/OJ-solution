#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
struct CARD
{
	int n,c;
	char ch;
};
string stra[]
{"A2345","23456","34567","45678","56789",
"6789T","789TJ","89TJQ","9TJQK","TJQKA"};
int color_toint(char c)
{
	if(c=='C')return 0;
	if(c=='D')return 1;
	if(c=='H')return 2;
	if(c=='S')return 3;
	return -1;
}
int num_toint(char c)
{
	if(c=='A')return 1;
	if(c=='T')return 10;
	if(c=='J')return 11;
	if(c=='Q')return 12;
	if(c=='K')return 13;
	return c-'0';
}
bool _1(CARD *a)
{
	int capp[4]={0};
	for(int i=0;i<5;i++)capp[a[i].c]++;
	bool flag=0;
	for(int i=0;i<5;i++)
		if(capp[i]==5)flag=1;
	if(!flag)return 0;
	string ns;
	for(int i=0;i<5;i++)ns+=a[i].ch;
	sort(ns.begin(),ns.end());
	for(int i=0;i<10;i++)if(ns==stra[i])return 1;
	return 0;
}
bool _2(CARD *a)
{
	int napp[14]={0};
	for(int i=0;i<5;i++)napp[a[i].n]++;
	for(int i=1;i<=13;i++)if(napp[i]==4)return 1;
	return 0;
}
bool _3(CARD *a)
{
	int napp[14]={0};
	for(int i=0;i<5;i++)napp[a[i].n]++;
	bool tw=0,tr=0;
	for(int i=1;i<=13;i++)
	{
		tw|=napp[i]==2;
		tr|=napp[i]==3;
	}
	return tw&&tr;
}
bool _4(CARD *a)
{
	int capp[4]={0};
	for(int i=0;i<5;i++)capp[a[i].c]++;
	for(int i=0;i<5;i++)if(capp[i]==5)return 1;
	return 0;
}
bool _5(CARD *a)
{
	string ns;
	for(int i=0;i<5;i++)ns+=a[i].ch;
	sort(ns.begin(),ns.end());
	for(int i=0;i<10;i++)if(ns==stra[i])return 1;
	return 0;
}
bool _6(CARD *a)
{
	int napp[14]={0};
	for(int i=0;i<5;i++)napp[a[i].n]++;
	bool tr=0;
	for(int i=1;i<=13;i++)tr|=napp[i]==3;
	return tr;
}
bool _7(CARD *a)
{
	int napp[14]={0};
	for(int i=0;i<5;i++)napp[a[i].n]++;
	int tw=0;
	for(int i=1;i<=13;i++)tw+=napp[i]==2;
	return tw==2;
}
bool _8(CARD *a)
{
	int napp[14]={0};
	for(int i=0;i<5;i++)napp[a[i].n]++;
	int tw=0;
	for(int i=1;i<=13;i++)tw+=napp[i]==2;
	return tw==1;
}
int check(CARD *a)
{
	if(_1(a))return 10;
	if(_2(a))return 9;
	if(_3(a))return 8;
	if(_4(a))return 7;
	if(_5(a))return 6;
	if(_6(a))return 5;
	if(_7(a))return 4;
	if(_8(a))return 3;
	return 2;
}
int ma;
vector<CARD> v;
vector<CARD> nv;
CARD tmp[5];
string ansname[]{
"straight-flush", 
"four-of-a-kind",
"full-house",
"flush",
"straight",
"three-of-a-kind",
"two-pairs",
"one-pair",
"highest-card"
};
void dfs(int x,int u)
{
	//cout<<x<<endl;
	if(x>=sz(v))
	{
		if(u!=5)return;
		for(int i=0;i<5;i++)tmp[i]=nv[i];
		ma=max(check(tmp),ma);
		return;
	}
	if(u<5)
	{
		nv.emplace_back(v[x]);
		dfs(x+1,u+1);
		nv.pop_back();
	}
	if(x<5)dfs(x+1,u);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<10;i++)sort(stra[i].begin(),stra[i].end());
	while(1)
	{
		v.clear();
		nv.clear();
		ma=0;
		string in;
		CARD now[5];
		CARD desk[5];
		for(int i=0;i<5;i++)
		{
			if((cin>>in)==0)return 0;
			if(i==0)cout<<"Hand: ";
			cout<<in<<' ';
			now[i].c=color_toint(in[1]);
			now[i].n=num_toint(in[0]);
			now[i].ch=in[0];
			v.emplace_back(now[i]);
		}
		cout<<"Deck: ";
		for(int i=0;i<5;i++)
		{
			cin>>in;
			cout<<in<<' ';
			desk[i].c=color_toint(in[1]);
			desk[i].n=num_toint(in[0]);
			desk[i].ch=in[0];
		}
		ma=check(now);
		for(int i=1;i<=5;i++)
		{
			//cout<<i<<"==="<<sz(v)<<endl;
			v.emplace_back(desk[i-1]);
			dfs(0,0);
		}
		cout<<"Best hand: ";
		cout<<ansname[10-ma]<<endl;
	}
	return 0;
}
