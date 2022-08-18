#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
struct node 
{
	node *next[10]={0};
	int cnt=0;
	bool isleaf=0;
};
node *root;
void insert(string &s)
{
	node *now=root;
	for(int i=0;i<s.size();i++)
	{
		if(now->next[s[i]-'0']==0)
			now->next[s[i]-'0']=new node();
		now=now->next[s[i]-'0'];
		now->cnt++;
	}
	now->isleaf=1;
}
bool dfs(node *now)
{
	if(now->isleaf&&now->cnt>=2)return 0;
	for(int i=0;i<10;i++)
	{
		if(now->next[i])
		{
			int re=dfs(now->next[i]);	
			if(re==0)return 0;
		}
	}
	return 1;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		root=new node();
		for(int i=0;i<n;i++)
		{
			string s;
			cin>>s;
			insert(s);
		}
		if(dfs(root))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

