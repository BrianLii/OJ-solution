#include<bits/stdc++.h>
#define EPS (1e-6)
using namespace std;
typedef pair<double,double> pii;
vector<pii> v;
bool cmp(pii &a,pii &b)
{
	return abs(a.first-b.first)<EPS?a.second>b.second:
		   a.first<b.first;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	double l,w;
	int n;
	while(cin>>n>>l>>w)
	{
		v.clear();
		for(int i=0;i<n;i++)
		{
			double p,r;
			cin>>p>>r;
			if(r<=w/2)continue;
			v.emplace_back(p-sqrt(r*r-(w/2)*(w/2)),
			               p+sqrt(r*r-(w/2)*(w/2)));
		}
		sort(v.begin(),v.end(),cmp);
		double last=0;
		int i=0,cnt=0;
		bool fail = 0;
		while(i<v.size())
		{
			if(last>=l)break;
			if(v[i].first>last)
			{
				cout<<-1<<endl;
				fail=1;
				break;
			}
			double tmp=last;
			int j=i;
			last=max(last,v[j].second);
			while(j+1<v.size()&&v[j+1].first<=tmp)
			{
				last=max(last,v[j+1].second);
				j++;
			}
			i=j+1;
			cnt++;
		}
		if(!fail)
		{
			if(last<l)cout<<-1<<endl;
			else cout<<cnt<<endl;
		}
		
	}
	return 0;
}

