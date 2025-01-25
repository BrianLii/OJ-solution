#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		cout<<"Case #"<<++cnt<<":\n";
		vector<string>ans;
		int ma=0;
		for(int i=0,ta;i<10;i++)
		{
			string in;
			cin>>in>>ta;
			if(ta>ma)
			{
				ans.clear();
				ma=ta;
				ans.push_back(in);
			}
			else if(ta==ma)
			{
				ans.push_back(in);
			}
		}
		for(string s:ans)cout<<s<<'\n';
	}
	return 0;
}

