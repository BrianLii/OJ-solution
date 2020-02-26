#include<bits/stdc++.h>
#include<vector>
using namespace std;
struct card
{
	char c;
	char x;
};
bool operator ==(card &_a,card &_b)
{
	return _a.c==_b.c||_a.x==_b.x;
}
vector<stack<card> >v;
bool check()
{
	for(int i=1;i<3&&i<v.size();i++)
	{
		stack<card> &now=v[i],&last1=v[i-1];
		if(now.top()==last1.top())
		{
			last1.push(now.top());
			now.pop();
			if(!now.size())v.erase(v.begin()+i);
			return 1;
		}
	}
	for(int i=3;i<v.size();i++)
	{
		stack<card> &now=v[i],&last3=v[i-3],&last1=v[i-1];
		if(now.top()==last3.top())
		{
			last3.push(now.top());
			now.pop();
			//cout<<"move "<<i<<" to "<<i-3<<endl;
			if(!now.size())v.erase(v.begin()+i);
			return 1;
		}
		else if(now.top()==last1.top())
		{
			last1.push(now.top());
			now.pop();
			//cout<<"move "<<i<<" to "<<i-1<<endl;
			if(!now.size())v.erase(v.begin()+i);
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n=52;
	string s1,s2;
	while(getline(cin,s1))
	{
		if(s1=="#")return 0;
		getline(cin,s2);
		stringstream ss;
		ss<<s1<<" "<<s2;
		v.clear();
		for(int i=0;i<n;i++)
		{
			stack<card> stk;
			card ca;
			ss>>ca.c>>ca.x;
			stk.push(ca);
			v.push_back(stk);
		}
		while(check());
		cout<<v.size()<<" pile"<<((v.size()>1)?"s":"")
		    <<" remaining:";
		for(auto i:v)
		{
			cout<<' '<<i.size();
		}
		cout<<endl;
	}
	return 0;
}

