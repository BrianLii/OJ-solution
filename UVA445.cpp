#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(getline(cin,s))
	{
		int cnt=0;
		for(char i:s)
		{
			if(i<='9'&&i>='0')cnt+=i-'0';
			else if(i=='b')
			{
				for(int j=0;j<cnt;j++)
					cout<<' ';
				cnt=0;		
			}
			else if(i=='!')cout<<endl;
			else 
			{
				for(int j=0;j<cnt;j++)
					cout<<i;
				cnt=0;
			}
		}
		cout<<endl;
	}
	return 0;
}

