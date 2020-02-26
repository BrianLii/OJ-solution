#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
bool isch(char c)
{
	return ((c<='Z'&&c>='A')||(c<='z'&&c>='a'));
}
bool isnum(char c)
{
	return (c<='9'&&c>='0');
}
struct node
{
	string s="";
	node *next=0;
	node(string &_s)
	{
		s=_s;
		next=0;
	}
	node(){}
};
node *root=new node();
node *tail=root;
void add(node *p,string &s)
{
	node *tmp=new node(s);
	tmp->next=p->next;
	p->next=tmp;
}
void add2(node *p,node *o)
{
	o->next=p->next;
	p->next=o;
}
void del(node *p)
{
	p->next=p->next->next;
}
node *find(node *p,int x)
{
	if(x==0)return p;
	return find(p->next,x-1);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string org;
	string ans;
	while(getline(cin,org))
	{
		if(org=="0")break;
		for(int i=0;i<org.size();i++)
		{
			if(isch(org[i]))
			{
				string tmp;
				tmp+=org[i];
				while(i+1<org.size()&&isch(org[i+1]))tmp+=org[++i];
				add(root,tmp);
				ans+=tmp;
			}
			else if(isnum(org[i]))
			{
				int now=org[i]-'0';
				while(i+1<org.size()&&isnum(org[i+1]))now=now*10+org[++i]-'0';
				node* tmp=find(root,now);
				ans+=tmp->s;
				del(find(root,now-1));
				add2(root,tmp);
			}
			else ans+=org[i];
		}
		ans+='\n';
	}
	cout<<ans;
	return 0;
}

