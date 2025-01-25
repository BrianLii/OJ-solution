#include<bits/stdc++.h>
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
//#include<iostream>
using namespace std;
int a[50];
vector<int> fans,nans;
int MIN_sum=1e9;
int dfs(int l,int num)
{
	if(num<0)return 1e9;
	if(num==0)
	{
		MIN_sum=0;
		fans=nans;
		return 0;
	}
	if(l==1)
	{
		if(num-a[l]<0)
		{
			if(num<MIN_sum)
			{
				MIN_sum=num;
				fans=nans;
			}
			return num;
		}
		else 
		{
			if(num-a[l]<MIN_sum)
			{
				MIN_sum=num-a[l];
				nans.push_back(a[l]);
				fans=nans;
				nans.pop_back();
			}
			return(num-a[l]);
		}
	}
	else 
	{
		nans.push_back(a[l]);
		int f=dfs(l-1,num-a[l]);
		nans.pop_back();
		int s=dfs(l-1,num);
		return min(f,s);
	}
}
int main()
{
	int N,T;
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>N>>T)
	{
		for(int i=1;i<=T;i++)cin>>a[i];
		int tmp = N-dfs(T,N);
		for(int i=fans.size()-1;i>=0;i--)cout<<fans[i]<<' ';
		cout<<"sum:"<<tmp<<endl;
		MIN_sum=1e9;
	}
}

