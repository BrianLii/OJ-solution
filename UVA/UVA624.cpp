//#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
#include<iostream>
using namespace std;
int a[50];
int dfs(int l,int num)
{
	if(num<0)return 1e9;
	if(num==0)return 0;
	if(l==1)
	{
		if(num-a[l]<0)return num;
		else return(num-a[l]);
	}
	else return min(dfs(l-1,num-a[l]),dfs(l-1,num));
}
int main()
{
	int N,T;
	while(cin>>N>>T)
	{
		for(int i=1;i<=T;i++)cin>>a[i];
		cout<<N-dfs(T,N)<<endl;
	}
	
}

