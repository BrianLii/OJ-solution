#include<bits/stdc++.h>
using namespace std;
int a[20][2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1)
	{
		memset(a,0,sizeof(a));
		string s;
		int cnt=-1;
		while(getline(cin,s))
		{
			if(s[0]=='.')break;
			cnt++;
			for(int i=0;i<s.size();i+=2)
			{
				if(s[i]=='+')a[cnt][1]^=(1<<(s[i+1]-'A'));
				else if(s[i]=='-')a[cnt][0]^=(1<<(s[i+1]-'A'));
			}
		}
		if(cnt==-1)break;
		int ma=(1<<16)-1;
		int sta;
		for(sta=0;sta<=ma;sta++)
		{
			int i;
			for(i=0;i<=cnt;i++)
				if(!((sta&(a[i][1]))||(~sta)&(a[i][0])))
					break;//not ok
			if(i>cnt)break;
		}
		if(sta>ma)cout<<"No pizza can satisfy these requests.\n";
		else 
		{
			cout<<"Toppings: ";
			for(int i=0;i<16;i++)
				if(sta&(1<<i))
					cout<<(char)(i+'A');
			cout<<endl;
		}
	}
 
	return 0;
}

