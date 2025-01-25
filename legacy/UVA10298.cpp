#include<bits/stdc++.h>
using namespace std;
bool check(string &s,string &p)
{
	bool fail=0;
	for(int i=0,len=s.size(),plen=p.size();i<len&&!fail;i++)
	{
		if(s[i]!=p[i%plen])fail=1;
	}
	return !fail;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		if(s==".")break;
		int l=s.size();
		vector<int> v,av;
		for(int i=1;i*i<=l;i++)
		{ 
			if(l%i==0)
			{
				v.push_back(i);
				if(i*i!=l)av.push_back(l/i);
			}
		} 
		auto itr=av.end();
		while(1)
		{
			itr--;
			v.push_back(*itr);
			if(itr==av.begin())break;
		}
		itr=v.begin();
		string p;
		for(int i=0;i<l;i++)
		{
			p+=s[i];
			if(i+1==(*itr))
			{
				if(check(s,p))
				{
					cout<<l/(i+1)<<endl;
					break;
				}
				itr++;
			}
		}
	}
	return 0;
}

