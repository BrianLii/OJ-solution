#include<bits/stdc++.h>
using namespace std;
struct TRIE
{
	struct node
	{
		node *next[27]={0};	
		bool isstring=0;
	};
	node *root;
	void init()
	{
		root=new node();
	}
	void insert(string &s)
	{
		node *now=root;
		for(char i:s)
		{
			if(now->next[i-'A']==0)
				now->next[i-'A']=new node();
			now=now->next[i-'A'];
		}
		now->isstring = 1;
	}
	bool find(string &s)
	{
		node *now=root;
		for(char i:s)
		{
			if(now->next[i-'A']==0)return 0;
			if(now->next[i-'A']->isstring)return 1;
			now=now->next[i-'A'];
		}
		return now->isstring;
	}
	bool in(string &s)
	{
		bool f=0;
		for(int i=0;i<s.size();i++)
		{
			string ss=s.substr(i);
			f|=find(ss);
		}
		return f;
	}
};
TRIE trie;
string now[260];
bool check(int p)
{
	string &s=now[p];
	for(int i=0,j=s.size()-1;i<j;i++,j--)
	{
		if(s[i]!=s[j])return 0; 
	}
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(cin>>s)
	{
		for(int i=0;i<258;i++)
		{
			now[i].clear();
		}
		int cnt=0;
		trie.init();
		for(int i=0;i<s.size();i++)
		{
			if(cnt>=2)break;
			for(int j=0;j+i<s.size();j++)
			{
				now[j]+=s[j+i];
				if(i>=2&&check(j)&&!(trie.in(now[j])))
				{
					//cout<<now[j]<<endl;
					trie.insert(now[j]);
					cnt++;
				}
			}
		}
		if(cnt>=2)cout<<s<<'\n';
	}
	return 0;
}

