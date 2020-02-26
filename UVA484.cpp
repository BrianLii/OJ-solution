#include<bits/stdc++.h>
using namespace std;
vector<int> v;
set<int> use;
multiset<int> all;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tmp;
	while(cin>>tmp)
	{
		v.push_back(tmp);
		all.insert(tmp);
	}
	for(int i:v)
	{
		if(use.find(i)==use.end()) 
		{
			use.insert(i);
			cout<<i<<' ';
			cout<<all.count(i)<<endl;
		}
	}
	return 0;
}

