#include<bits/stdc++.h>
using namespace std;

stack<int> s1,s2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int cnt=0;
	while(cin>>n)
	{
		if(!n)return 0;
		if(cnt++)cout<<endl;
		vector<int> ans;
		string in;
		getline(cin,in);
		while(getline(cin,in))
		{
			if(in=="0")break;
			
			stringstream ss;
			ss<<in;
			int tmp;
			ans.clear();
			while(ss>>tmp)
			{
				if(!tmp)break;
				ans.push_back(tmp);
			}
			while(s1.size())s1.pop();
			while(s2.size())s2.pop();
			bool flag=0;
			for(int i=n;i>=1;i--)s1.push(i);
			for(int i=0;i<ans.size();i++)
			{
				int f=ans[i];
				if(!s2.empty()&&s2.top()==f)
				{
					s2.pop();
					continue;
				}
				if(s1.empty()||(!s1.empty()&&s1.top()>f))
				{
					cout<<"No"<<endl;
					flag=1;
					break;
				}
				while(!s1.empty())
				{
					if(s1.top()<f)
					{
						s2.push(s1.top());
						s1.pop();	
					}
					if(s1.top()==f)
					{
						s1.pop();
						break;
					}
				}
			}
			if(!flag)cout<<"Yes"<<endl;
		}
	}
	return 0;
}
 
