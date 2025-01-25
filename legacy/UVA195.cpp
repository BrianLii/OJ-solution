#include<bits/stdc++.h>
using namespace std;
string s;
int l;
string ans;
int visit[100000];
void dfs(int p)
{
	if(p==l)
	{
		for(char i:ans)cout<<i;
		cout<<endl;
	}
	char last = 0;
	for(int i=0;i<l;i++)
	{
		if(!visit[i]&&s[i]!=last)
		{
			visit[i]=1;
			last=s[i];
			ans+=s[i];
			dfs(p+1);
			visit[i]=0;
			ans.pop_back();
		}
	}
}
bool cmp(char a,char b)
{
	int tmpa=toupper(a),tmpb=toupper(b);
	if(tmpa==tmpb)return a<b;
	else return tmpa<tmpb;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;
		l=s.size();
		sort(s.begin(),s.end(),cmp);
		dfs(0);
	}
	
	return 0;
}

