#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int a;
		set<int>s;
		int ma=0;
		cin>>n;
		while(n--)
		{
			cin>>a;
			if(s.find(a)==s.end())
			{
				s.insert(a);
				ma=max(ma,(int)s.count());
			}
			else
			{
				ma=max(ma,(int)s.count());
				s.clear();
				s.insert(a);
			}
		}
		ma=max(ma,(int)s.count());
		cout<<ma<<'\n';
	}
	return 0;
}

