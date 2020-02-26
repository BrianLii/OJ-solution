#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n==0)
		{
			cout<<10<<endl;
			continue;
		}
		stack<int>stk;
		for(int i=9;i>=2;i--)
		{
			while(n%i==0)
			{
				n/=i;
				stk.push(i);
			}
		}
		if(n>1)cout<<-1;
		else while(stk.size())
		{
			cout<<stk.top();
			stk.pop(); 
		}
		cout<<endl;
	}
	return 0;
}

