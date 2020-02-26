#include<bits/stdc++.h>
#define endl '\n'
#define EM emplace
#define EM_back emplace_back
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
struct node
{
	node *next[2]={0};
	int cnt=0,dep=0;
};
node *root;
void insert(string &s)
{
	node *now=root;
	for(char i:s)
	{
		if(now->next[i-'0']==0)now->next[i-'0']=new node();
		now->next[i-'0']->dep=now->dep+1;
		now=now->next[i-'0'];
		now->cnt++;
	}
}
int dfs(node *now)
{
	if(!now)return 0;
	int ans=(now->cnt)*(now->dep);
	ans=max(dfs(now->next[0]),ans);
	ans=max(dfs(now->next[1]),ans);
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
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
		cout<<dfs(root)<<endl;
	}
	return 0;
}

