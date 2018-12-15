#include<bits/stdc++.h>
#define pb(x) emplace_back(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string s1,s2;
int pre[10000],in[10000];
struct node
{
	char num;
	node *l,*r;
};
node *root;
node *build(int l,int r)
{
	if(l>r)return nullptr;
	//cout<<l<<' '<<r<<endl;
	///find root in the segment
	int rt=-100,mi=99;
	for(int i=l;i<=r;i++)
	{
		if(pre[s2[i]]<mi)
		{
			mi=pre[s2[i]];
			rt=i;
		}
	}
	node *tmp=new node;
	if(rt==-100)
	{
		tmp->num=rt;
		return tmp;
	}
	tmp->l=build(l,rt-1);
	tmp->r=build(rt+1,r);
	tmp->num=rt;
	return tmp;
}
void dfs(node *x)
{
	if(!x)return;
	dfs(x->l);
	dfs(x->r);
	cout<<s2[x->num];
}
void remove(node *x)
{
	if(!x)return;
	remove(x->l);
	delete x->l;
	remove(x->r);
	delete x->r;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>s1>>s2)
	{
		for(int i=0;i<s1.size();i++)
		{
			pre[s1[i]]=i;
		}
		for(int i=0;i<s2.size();i++)
		{
			in[s2[i]]=i;
		}
		root = build(0,s1.size()-1);
		dfs(root);
		remove(root);
		cout<<'\n';	
	}
	return 0;
}

