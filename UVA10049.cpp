#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool cmp(pii _a, pii _b)
{
	return _a.second<_b.second;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n=20000000;
	vector<pii>v;
	v.push_back(pii(2,3));
	int now=0;
	int i;
	for(i=3;i<=n&&v.back().second<=2000000100;i++)
	{
		if(i>v[now].second)now++;
		//cout<<v[now].first<<' ';
		v.push_back(pii(i,v.back().second+v[now].first));
	}
	int len = v.size()-1;
	int in;
	while(cin>>in)
	{
		if(!in)break;
		if(in==1)cout<<1<<endl;
		else if(in==2)cout<<2<<endl;
		else
		{
			auto tmp=*lower_bound(v.begin(),v.end(),pii(12211,in),cmp);
			cout<<tmp.first<<endl;
		}
		
	}
	return 0;
}

