#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define sz(x) ((int)x.size())
#define maxn 100020
#define IMA ((int)INT_MAX)
#define IMI ((int)INT_MIN)
using namespace std;
int a[maxn+20];
int toint(string &s)
{
	int now=0;
	for(int i=s[0]=='-';i<s.size();i++)
	{
		now=now*10+s[i]-'0';
	}
	if(s[0]=='-')return -1*now;
	else return now;
}
bool un[maxn+20];
int ma[maxn+20];
bool fr[maxn+20];
bool vis[maxn+20];
bool solve(vector<int> v)
{
	reverse(v.begin(),v.end());
	vector<int> val;
	val.resize(sz(v)+2);
	val[0]=INT_MAX;
	for(int i=0;i<v.size();i++)
	{
		if(un[v[i]])fr[i]=1;
		val[i+1]=(a[v[i]]);
	}
	val[sz(v)+1]=(INT_MIN);
	int nma=val.back();
	for(int i=sz(val)-2;i>0;i--)
	{
		nma++;
		ma[i]=nma;
		nma=max(val[i],nma);
	}
	for(int i=1;i<=sz(val)-2;i++)
	{
		if(fr[i])
		{
			int l=val[i-1]-1;
			int r=mi[i];
			if(l*r<=0)val[i]=0;
			
		}
		else
		{
			if(!(val[i-1]>val[i+1]&&val[i]>=ma[i]))return 0;
		}
	}
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s=="?")
		{
			a[i]=1e9+10;
			un[i]=1;	
		}
		else a[i]=toint(s);
	}
	for(int i=n;i>=1;i--)
	{
		if(vis[i])continue;
		vector<int> now;
		if(k!=1)for(int j=i;j>=1;j-=k-1)
		{
			vis[j]=1;
			now.emplace_back(j);	
		}
		else 
		{
			vis[i]=1;
			now.emplace_back(i);	
		}
		///for(int i:now)cout<<i<<' ';
		//cout<<endl;
		solve(now);
	}
	return 0;
}
/*
10 4
10 9 8 7 6 5 -5 -6 -7 -8 -9
*/
