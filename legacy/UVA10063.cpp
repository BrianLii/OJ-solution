#include<bits/stdc++.h>
using namespace std;
struct node
{
	char c=0;
	node *next=0;
	node (char h)
	{
		c=h;
	}
	node()
	{
		c=0;
		next=0;
	}
};
node *root;
string s;
void insert(node *pos,char c)
{
	node *tmp=new node(c);
	tmp->next=pos->next;
	pos->next=tmp; 
}
void remove(node *last)
{
	if(!last->next)return;
	last->next=last->next->next;
}
void dfs(int x)
{
	node *now=root;
	if(x==s.size())
	{
		now=now->next;
		while(now)
		{
			cout<<(now->c);
			now=now->next;
		}
		cout<<endl;
		return;
	}
	while(now)
	{
		insert(now,s[x]);
		dfs(x+1);
		remove(now);
		now=now->next;
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int cnt=0;
	while(cin>>s)
	{
		if(cnt++)cout<<endl;
		root=new node();
		root->next=new node(s[0]); 
		dfs(1);
		delete root->next;
	}
	return 0;
}

