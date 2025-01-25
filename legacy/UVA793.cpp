#include<bits/stdc++.h>
using namespace std;
struct DSU
{
	int lead[1020];
	void _init(int size)
	{
		for(int i=0;i<=size;i++)lead[i]=i;
	}
	int find(int x)
	{
		if(lead[x]==x)return x;
		else return lead[x]=find(lead[x]);
	}
	void U(int x,int y)
	{
		lead[find(x)]=find(y);
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
DSU dsu;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		char c;
		int a,b,can=0,cant=0;
		dsu._init(n);
		string in;
		getline(cin,in);
		while(getline(cin,in))
		{
			if(in=="")break;
			stringstream ss;
			ss<<in;
			while(ss>>c>>a>>b)
			{
				if(c=='q')
				{
					if(dsu.same(a,b))can++;
					else cant++;
				}
				else
				{
					dsu.U(a,b);
				}
			}
		}
		cout<<can<<','<<cant<<endl<<endl;
	}
	return 0;
}

