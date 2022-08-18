#include<bits/stdc++.h>
using namespace std;
int app[40200];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b;
	while(cin>>a>>b)
	{
		memset(app,0,sizeof(app));
		cout<<a<<'/'<<b<<" = "; 
		cout<<a/b;
		
		a%=b;
		string s;
		s+='.';
		int st=INT_MAX;
		int cnt=0;
		for(int i=1;;i++)
		{
			a*=10;
			if(app[a])
			{
				st=app[a];
				break;	
			}
			app[a]=i;
			s+=a/b+'0';
			cnt++;
			a%=b;
		}
		
		for(int i=0;i<=cnt&&i<=50;i++)
		{
			if(i==st)cout<<'(';
			cout<<s[i];
		}
		if(cnt-st+1>50)cout<<"...";
		cout<<')'<<endl;
		cout<<"    "<<cnt-st+1<<" = number of digits in repeating cycle"<<endl;
		cout<<endl;
	}
		
	return 0;
}

