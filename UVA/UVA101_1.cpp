#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
stack<int> st[30];
int pos[30];
void out(stack<int> &stk)
{
	if(!stk.size())return ;
	int tmp=stk.top();
	stk.pop();
	out(stk);
	cout<<' '<<tmp;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			st[i]=st[29];
			st[i].push(i);
			pos[i]=i;
		}
		string s;
		while(cin>>s)
		{
			if(s=="move")
			{
				int a,b;
				cin>>a>>s>>b;
				if(pos[a]==pos[b])continue;
				if(s=="onto")
				{
					while(st[pos[a]].top()!=a)
					{
						st[st[pos[a]].top()].push(st[pos[a]].top());
						pos[st[pos[a]].top()]=st[pos[a]].top();
						st[pos[a]].pop();
					}
					while(st[pos[b]].top()!=b)
					{
						st[st[pos[b]].top()].push(st[pos[b]].top());
						pos[st[pos[b]].top()]=st[pos[b]].top();
						st[pos[b]].pop();
					}
					st[pos[a]].pop();
					st[pos[b]].push(a);
					pos[a]=pos[b];
				}
				else 
				{
					while(st[pos[a]].top()!=a)
					{
						st[st[pos[a]].top()].push(st[pos[a]].top());
						pos[st[pos[a]].top()]=st[pos[a]].top();
						st[pos[a]].pop();
					}
					st[pos[a]].pop();
					st[pos[b]].push(a);
					pos[a]=pos[b];
				}
			}
			else if(s=="pile")
			{
				int a,b;
				cin>>a>>s>>b;
				if(pos[a]==pos[b])continue;
				if(s=="onto")
				{
					while(st[pos[b]].top()!=b)
					{
						st[st[pos[b]].top()].push(st[pos[b]].top());
						pos[st[pos[b]].top()]=st[pos[b]].top();
						st[pos[b]].pop();
					}
					stack<int> tmp;
					while(st[pos[a]].top()!=a)
					{
						pos[st[pos[a]].top()]=pos[b];
						tmp.push(st[pos[a]].top());
						st[pos[a]].pop();
					}
					st[pos[a]].pop();
					st[pos[b]].push(a);
					pos[a]=pos[b];
					while(tmp.size())
					{
						st[pos[b]].push(tmp.top());
						tmp.pop();
					}
					
				}
				else 
				{
					stack<int> tmp;
					while(st[pos[a]].top()!=a)
					{
						pos[st[pos[a]].top()]=pos[b];
						tmp.push(st[pos[a]].top());
						st[pos[a]].pop();
					}
					st[pos[a]].pop();
					st[pos[b]].push(a);
					pos[a]=pos[b];
					while(tmp.size())
					{
						st[pos[b]].push(tmp.top());
						tmp.pop();
					}
					
				}
			}
			else 
			{
				break;
			}
		}
		for(int i=0;i<n;i++)
		{
			cout<<i<<':';
			out(st[i]);
			cout<<endl;
		}
	}
	return 0;
}

