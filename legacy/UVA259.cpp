#include<bits/stdc++.h>
using namespace std;
string app;
vector<int> cnt;
vector<string> p;
bool isok(int x,int idx)
{
	for(int i:p[idx])
	{
		if(i-'0'==x)return 1;
	}
	return 0;
}
string ans;
string fans;
int sum;
bool dfs(int x,int count)
{
	if(x==10)
	{
		if(count!=sum)return 0;
		fans=ans;
		return 1;	
	}
	bool flag=0;
	for(int i=0;i<app.size();i++)
	{
		if(cnt[i]&&isok(x,i))
		{
			cnt[i]--;
			ans+=app[i];
			flag |=dfs(x+1,count+1);
			cnt[i]++;
			ans.pop_back();
		}
	}
	ans+='_';
	flag |=dfs(x+1,count);
	ans.pop_back();
	return flag;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1)
	{
		app="";
		cnt.clear();
		p.clear();
		string in;
		ans.clear();
		fans.clear();
		sum=0;
		while(getline(cin,in))
		{
			if(in=="")break;
			app+=in[0];
			cnt.push_back(in[1]-'0');
			sum+=in[1]-'0';
			p.push_back(in.substr(3));
		}
		if(app.size()==0)break;
		if(sum>10)cout<<"!\n";
		else
		{
			if(dfs(0,0))cout<<fans<<endl;
			else cout<<"!\n"; 
		}
	}
	return 0;
}

