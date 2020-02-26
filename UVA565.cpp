#include<bits/stdc++.h>
using namespace std;
int a[20][20];
int cnt=-1;
inline bool check(int x)
{
	bool flag=1;
	for(int i=0;i<=cnt&&flag;i++)
	{
		bool flag2=0;
		for(int j=0;j<16&&!flag2;j++)
		{
			if((x&(1<<j))&&a[i][j]==1)
			{
			}flag2=1;
			else if((!(x&(1<<j)))&&a[i][j]==2)flag2=1;
		}
		flag&=flag2;
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(1)
	{
		cnt=-1;
		memset(a,0,sizeof(a));
		
		while(getline(cin,s))
		{
			if(s==".")break;
			++cnt;
			for(int i=0,len=s.size();i<len;i+=2)
			{
				if(s[i]=='+')
					a[cnt][s[i+1]-'A']=1;
				else if(s[i]=='-')
					a[cnt][s[i+1]-'A']=2;
			}
		}
		if(cnt==-1)break;
		int ma=(1<<16)-1;
		int i;
		for(i=0;i<=ma;i++)
		{
			if(check(i))break;
		}
		if(i>ma)cout<<"No pizza can satisfy these requests."<<'\n';
		else	
		{
			cout<<"Toppings ";
			for(int j=0;j<16;j++)
				if(bool(i&(1<<j)))cout<<(char)(j+'A');	
			cout<<'\n';
		}
	}
	return 0;
}

