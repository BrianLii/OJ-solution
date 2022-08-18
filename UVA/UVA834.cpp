#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b)
	{
		vector<int> v;
		while(b)
		{
			v.push_back(a/b);
			a%=b;
			swap(a,b);
		}
		if(v.size()==1)
		{
			cout<<'['<<v.back()-1<<';'<<1<<']'<<endl;
		}
		else
		{
			cout<<'[';
			cout<<v[0]<<';';
			for(int i=1;i<v.size()-1;i++)cout<<v[i]<<',';
			cout<<v.back()<<']'<<endl;
		}
	}
	return 0;
}

