#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	while(cin>>in)
	{
		string ns;
		for(int i=0;i<in.size();i++)
		{
			if(in[i]<='Z'&&in[i]>='A')ns+=in[i]-'A'+'a';
			else if(in[i]<='z'&&in[i]>='a')ns+=in[i];
			else 
			{
				if(ns!="")v.push_back(ns);
				ns.clear();
			}
		}
		if(ns!="")v.push_back(ns);
	}
	sort(v.begin(),v.end());
	string last;
	for(string s:v)
	{
		if(s!=last)cout<<s<<endl;
		last=s;
	}
	return 0;
}

