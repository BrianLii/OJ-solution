#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
//#include<iostream>
using namespace std;
string s[70];
bool cmp(string s1,string s2)
{
	if(s1+s2>s2+s1)return 1;
	else return 0;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)break;
		for(int i=0;i<n;i++)
		{
			cin>>s[i];
		};
		sort(s,s+n,cmp);
		for(int i=0;i<n;i++)
		{
			cout<<s[i];
		}
		cout<<endl;
	} 
	
}

