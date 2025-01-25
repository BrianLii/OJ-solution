#include<bits/stdc++.h>
using namespace std;
int pos[50];
stack<int> stk[50];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	getline(cin,trash);
	for(int i=0;i<n;i++)
	{
		stk[i].push(i);
		pos[i]=i;	
	}
	string s1,s2,trash;
	while(cin>>s1)
	{
		if(s1=="quit")break;
		int a,b;
		cin>>a>>s2>>b;
		if(s1=="move"&&s2=="onto")
		{
			while(!stk[pos[a]].empty())
			{
				int now=stk[pos[a]].top();
				stk[pos[a]].pop();
				if(now==a)
			}
		}
		else if(s1=="move"&&s2=="over")
		{
			
		}
		else if(s1=="pile"&&s2=="onto")
		{
			
		}
		else if(s1=="pile"&&s2=="over")
		{
			
		}
	}
	return 0;
}

