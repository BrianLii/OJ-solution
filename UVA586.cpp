#include<bits/stdc++.h>
//#define endl '\n'
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
	int a[12]={0};
	void shift()
	{
		for(int i=11;i>0;i--)a[i]=a[i-1];
		a[0]=0;
	}
	void tims(int x)
	{
		for(int i=11;i>=0;i--)a[i]*=x;
	}
	void add(node &x)
	{
		for(int i=11;i>=0;i--)a[i]+=x.a[i];
	}
};
struct sta
{
	string tp;
	int num=0;
};
int toint(string &s)
{
	int ans=0;
	for(char i:s)
	{
		ans*=10;
		ans+=i-'0';
	}
	return ans;
}
vector<sta> pro;
int match[1000020];
node solve(int l,int r)
{
	node res;
	sta &now=pro[l];
	if(l==r)
	{
		res.a[0]=now.num;
		return res;	
	}
	int i=l;
	while(1)
	{
		i++;
		if(i==r)break;
		node tmp=solve(i,match[i]);
		if(now.num==-1)tmp.shift();
		else tmp.tims(now.num);
		res.add(tmp);
		i=match[i];
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	string in;
	while(cin>>in)
	{
		sta tmp;
		if(in=="BEGIN")
		{
			tmp.tp="BEGIN";
			tmp.num=1;
			pro.emplace_back(tmp);
		}
		else if(in=="LOOP")
		{
			tmp.tp="LOOP";
			cin>>in;
			if(in=="n")tmp.num=-1;
			else tmp.num=toint(in);
			pro.emplace_back(tmp);
		}
		else if(in=="OP")
		{
			tmp.tp="OP";
			cin>>in;
			tmp.num=toint(in);
			pro.emplace_back(tmp);
		}
		else
		{
			tmp.tp="END";
			pro.emplace_back(tmp);
		}
	}
	stack<int>stk;
	for(int i=0;i<sz(pro);i++)
	{
		if(pro[i].tp=="END")
		{
			match[stk.top()]=i;
			match[i]=stk.top();
			stk.pop();
		}
		else if(pro[i].tp!="OP")
		{
			stk.emplace(i);
		}
		else match[i]=i;
	}
	/*
	cout<<endl;
	for(int i=0;i<sz(pro);i++)
	{
		cout<<i<<' '<<pro[i].tp<<' '<<pro[i].num<<' '<<match[i]<<endl;
	}
	cout<<endl;
	*/
	int now=0;
	int CNT=0;
	while(now<sz(pro))
	{
		if(now)cout<<endl;
		node re=solve(now,match[now]);
		
		cout<<"Program #"<<++CNT<<endl;
		cout<<"Runtime = ";
		int *p=re.a;
		bool pflag=0;
		for(int i=11;i>=2;i--)
		{
			if(p[i]>0)
			{
				if(pflag)cout<<'+';
				pflag=1;
				if(p[i]!=1)cout<<p[i]<<'*';
				cout<<"n^"<<i;
			}
		}
		if(p[1]>0)
		{
			if(pflag)cout<<'+';
			pflag=1;
			if(p[1]!=1)cout<<p[1]<<'*';
			cout<<'n';
		}
		if(p[0]>0)
		{
			if(pflag)cout<<'+';
			pflag=1;
			cout<<p[0];
		}
		if(!pflag)cout<<0;
		cout<<endl;
		now=match[now]+1;
	}
	cout<<endl;
	return 0;
}
/*
BEGIN
	LOOP 3
	   LOOP 7
		  OP 4
	   END
	   OP 4
    END
END
*/	    
