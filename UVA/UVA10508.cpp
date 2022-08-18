#include<bits/stdc++.h>
using namespace std;
/*inline int con(char c)
{
	if(c<='Z')return c-'A';
	else return c-'a'; 
}
struct node
{
	node *next[26*2+5];
	bool isword = 0;
};
node *root;
void insert(string s)
{
	node *np=root;
	for(int i=0;i<s.size();i++)
	{
		if(np->next[con(s[i])]==nullptr)
		{
			np->next[con(s[i])]=new node();
		}
		np=np->next[con(s[i])];
	}
	np->isword = 1;
}
bool search(string s)
{
	node *np=root;
	for(int i=0;i<s.size();i++)
	{
		if(np->next[con(s[i])]==nullptr)return 0;
		np=np->next[con(s[i])]; 
	}
	return np->isword;
}*/
string s[1000000];
string start;
int n, l;
inline int cal(string a)
{
	int ans=0;
	for(int i=0;i<l;i++)
		if(a[i]!=start[i])ans++;
	return ans;
}
struct cmp
{
	bool operator()(string s1,string s2)
	{
		return cal(s1)<cal(s2);
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n>>l)
	{
		cin>>start;
		n--;
		for(int i=0;i<n;i++)cin>>s[i];
		sort(s,s+n,cmp());
		cout<<start<<'\n';
		for(int i=0;i<n;i++)
		{
			cout<<s[i]<<'\n';
		}
	}
	return 0;
}

