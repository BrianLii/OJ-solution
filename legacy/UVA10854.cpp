#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
typedef pair<int,int> pii;
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		string in;
		s="";
		while(cin>>in)
		{
			if(in=="ENDPROGRAM")break;
			else if(in=="IF")s+='(';
			else if(in=="ELSE")s+='[';
			else if(in=="END_IF")s+="])"; 
		}
		stack<pii> stk;
		int ans=1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='(')stk.push(pii(1,0));
			else if(s[i]=='[')stk.push(pii(2,0));
			else if(s[i]==']')
			{
				int tmp=stk.top().second;
				stk.pop();
				if(tmp==0)tmp=1;
				if(stk.top().first==1&&stk.top().second==0)
					stk.top().second+=1;
				stk.top().second+=tmp;
			}
			else if(s[i]==')')
			{
				int tmp=stk.top().second;
				stk.pop();
				if(tmp==0)tmp=1;
				if(stk.size())
					stk.top().second+=tmp;
				else 
				  ans*=tmp;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

