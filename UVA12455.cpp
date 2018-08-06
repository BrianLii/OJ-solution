//#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
#include<iostream>
using namespace std;
int a[1200];
int n,p;
int dfs(int l,int num)
{
	if(num==0)return 1;
	if(l==1&&num==a[1])return 1;
	if(l==1)return 0;
	return dfs(l-1,num-a[l])||dfs(l-1,num);//pick,not pick
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>p;
		for(int i=1;i<=p;i++)cin>>a[i];
		if(dfs(p,n))cout<<"YES\n";
		else cout<<"NO\n"; 
	}
	
}

