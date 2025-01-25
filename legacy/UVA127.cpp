#include<bits/stdc++.h>
using namespace std;
struct card
{
	char c;
	int x;
};
struct node
{
	card v;
	node *next,*last;	
	bool isrt=0;
};
node *root=new node();
bool check()
{
	node *now=root;
	while(now->next)
	{
		now=now->next;
		if(now->last&&now->last->last
			&&now->last->last->last&&
			now->last->last->last->v)
			
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	node *now=root;
	for(int i=0;i<52;i++)
	{
		now->next=new node();
		now->next->last=now;
		now=now->next;
		cin>>now->v;
	}
	while()
	return 0;
}

