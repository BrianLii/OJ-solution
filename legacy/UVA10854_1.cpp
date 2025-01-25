#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
int pos[1000000];
string s;
int cal(int l,int r)
{
	//cout<<l<<' '<<r<<endl;
	if(r==l+1||l>r)return 1;
	if(s[l]=='(')
	{
		int p=pos[r-1];
		int ans=1;
		for(int i=l+1;i<p;)
		{
			ans*=cal(i,pos[i]);
			i=pos[i]+1;
		}
		ans+=cal(p,r-1);
		return ans;
	}
	else
	{
		int ans=1;
		for(int i=l+1;i<r;)
		{
			ans*=cal(i,pos[i]);
			i=pos[i]+1;
		}
		return ans;
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		s="";
		string in;
		while(cin>>in)
		{
			if(in=="IF")s+='(';
			else if(in=="ELSE")s+='[';
			else if(in=="END_IF")s+="])";
			else if(in=="ENDPROGRAM")break;
		}
		stack<int> stk;
		s="["+s+"]";
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='('||s[i]=='[')stk.push(i);
			else 
			{
				pos[stk.top()]=i;
				pos[i]=stk.top();
				stk.pop();
			}
		}
		//cout<<s<<endl;
		cout<<cal(-1,s.size())<<endl;		
	}
	return 0;
}

