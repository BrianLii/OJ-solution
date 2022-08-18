#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
vector<string> v;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	while(getline(cin,in))
	{
		if(in=="0")break;
		v.push_back(in);
	}
	deque<string> deq;
	for(auto s:v)
	{
		for(int i=0;i<s.size();i++)
		{
			if(s[i]<='9'&&s[i]>='0')
			{
				int num=0;
				while(i<s.size()&&s[i]<='9'&&s[i]>='0')
				{
					num=num*10+s[i]-'0';
					i++;
				}
				i--;
				cout<<deq[num-1];
			}
			else if((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A'))
			{
				string now;
				while(i<s.size()&&((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A')))
				{
					now+=s[i];
					i++;
				}
				deq.push_front(now);
				cout<<now;
				i--;
			}
			else
			{
				cout<<s[i];
			}
		}
		cout<<endl;
	}
	return 0;
}

