#include<bits/stdc++.h>
using namespace std;
struct sta
{
	int c1,c2;
	string s;
	sta(int a,int b)
	{
		c1=a;
		c2=b;
	}
	sta()
	{
		c1=-100;
		c2=-100;
	}
};
int c1, c2,val;
sta last[1000*10000+3000];
int use[1000*10000+3000];
int cnt=1;
inline int con(sta a)
{
	return a.c1*10000+a.c2;
}
void rec(sta n)
{
	cout<<last[con(n)].c1<<' ';
	if(last[con(n)].c1==-1)return;
	rec(last[con(n)]);
	cout<<n.s<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>c1>>c2>>val)
	{
		queue<sta> q;
		sta t=sta(0,0);
		last[con(t)]=sta(-1,-1);
		q.push(t);
		while(!q.empty())
		{
			sta now=q.front();
			q.pop();
			if(now.c1==val||now.c2==val)
			{
				rec(now);
				cout<<"success"<<endl;
				/*cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;
				now=last[con(now)];
				cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;
				now=last[con(now)];
				cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;
				now=last[con(now)];
				cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;
				now=last[con(now)];
				cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;
				now=last[con(now)];
				cout<<last[con(now)].c1<<' '<<last[con(now)].c2<<endl;*/
				break;
			}
			
			sta tmp;
			
			//A -> B
			if(now.c1<=c2-now.c2)
			{
				tmp=sta(0,now.c2+now.c1);
			}
			else if(now.c1>c2-now.c2)
			{
				tmp=sta(now.c1-(c2-now.c2),c2);
			}
			tmp.s="pour A B";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}		
			
			//B -> A
			if(now.c2<=c1-now.c1)
			{
				tmp=sta(now.c1+now.c2,0);
			}
			else if(now.c2>c1-now.c1)
			{
				tmp=sta(c1,now.c2-(c1-now.c1));
			}
			tmp.s="pour B A";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}	
			
			//empty A
			tmp=sta(0,now.c2);
			tmp.s="empty A";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}	
			
			//empty B
			tmp=sta(now.c1,0);
			tmp.s="empty A";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}	
			
			//fill A
			tmp=sta(c1,now.c2);
			tmp.s="fill A";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}	
			
			//fill B 
			tmp=sta(now.c1,c2);
			tmp.s="fill B";
			if(use[con(tmp)]!=cnt)
			{
				use[con(tmp)]=cnt;
				last[con(tmp)]=now;
				q.push(tmp);
			}	
		}
	}
	return 0;
}

