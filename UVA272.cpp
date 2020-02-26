#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	bool flag=1;
	while(getline(cin,s))
	{
		for(char i:s)
		{
			if(i=='\"')
			{
				if(flag)cout<<"``";
				else cout<<"\'\'";
				flag=!flag;
			}
			else cout<<i; 
		}
		cout<<endl;
	}
	return 0;
}

