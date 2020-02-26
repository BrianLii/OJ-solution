#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
typedef long double DB;
DB cost[][5]{
{0.10,0.06,0.02},
{0.25,0.15,0.05},
{0.53,0.33,0.13},
{0.87,0.47,0.17},
{1.44,0.80,0.30}};
int part(int T)
{
	T%=60*24;
	if(8*60<T&&T<=18*60)return 0;
	if(18*60<T&&T<=22*60)return 1;
	return 2;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	char c;
	cout<<fixed<<setprecision(2); 
	string in;
	while(cin>>c>>in)
	{
		int h1,m1,h2,m2;
		cin>>h1>>m1>>h2>>m2;
		int T1=60*h1+m1;
		int T2=60*h2+m2;
		if(T2<=T1)T2+=60*24;
		DB ans=0;
		int tmp[3]={0};
		for(int i=T1+1;i<=T2;i++)
		{
			tmp[part(i)]++;
			ans+=cost[c-'A'][part(i)];
		}
		cout<<setw(10)<<in;
		for(int i=0;i<3;i++)cout<<setw(6)<<tmp[i];
		cout<<"  "<<c<<setw(8)<<ans<<endl;
	}
	return 0;
}

