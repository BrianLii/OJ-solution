#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int d,n;
	string s;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>d)
	{
		if(!n&&!d)break;
		int len=n-d;
		cin>>s;
		deque<char> q;
		for(int i=0;i<n;i++)
		{
			while(d>0&&q.size()&&q.back()<s[i])
			{
				d--;
				q.pop_back();	
			}
			q.push_back(s[i]);
		}
		for(int i=0;i<len;i++)
		{
			cout<<q.front();
			q.pop_front();
		}
		cout<<'\n';
	}
	return 0;
}

