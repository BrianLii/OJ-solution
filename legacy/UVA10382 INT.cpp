#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sort(v.begin(),v.end());
	cnt=1;
	int i=0;
	int n,l,w;
	while(i<v.size())
	{
		int last=v[i].second;
		int ma=-100000;
		if(i+1==v.size())
		{
			if(last>=w)cout<<cnt<<endl;
			else cout<<'-1';
		}
		if(v[i+1].first>last)
		{
			cout<<-1<<endl;
			return 0;
		}
		while(i+1<v.size()&&v[i+1].first<=last)
		{
			i++;
			ma=max(ma,v[i].second)
		}
		last=ma;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

