#include<bits/stdc++.h>
using namespace std;
int cal(int x)
{
	while(x>9)
	{
		int now=0;
		while(x)
		{
			now+=x%10;
			x/=10;
		}
		x=now;
	}
	return x;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2,ss1,ss2;
	while(getline(cin,s1))
	{
		getline(cin,s2);
		ss1="";
		ss2="";
		for(char i:s1)
		if((i<='z'&&i>='a')||((i<='Z'&&i>='A')))
			ss1+=i;
		for(char i:s2)
			if((i<='z'&&i>='a')||((i<='Z'&&i>='A')))
				ss2+=i;
		int a1=0,a2=0;
		for(int i:ss1)
		{
			if(i<='z'&&i>='a')a1+=i-'a'+1;
			else a1+=i-'A'+1;
		}
		for(int i:ss2)
		{
			if(i<='z'&&i>='a')a2+=i-'a'+1;
			else a2+=i-'A'+1;
		}
		a1=cal(a1);
		a2=cal(a2);
		if(a1>a2)swap(a1,a2);
		cout<<fixed<<setprecision(2)
			<<((double)a1)/a2*100<<'%'<<endl; 
	}
	
	return 0;
}

