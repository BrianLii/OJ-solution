#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
string pad[10][5]{{" - ",
                   "| |",
                   "   ",
				   "| |", 
				   " - "},
				   
				  {"   ",
                   "  |",
                   "   ",
				   "  |", 
				   "   "},
				   
				  {" - ",
                   "  |",
                   " - ",
				   "|  ", 
				   " - "},
				   
				  {" - ",
                   "  |",
                   " - ",
				   "  |", 
				   " - "},
				   
				  {"   ",
                   "| |",
                   " - ",
				   "  |", 
				   "   "},
				   
				  {" - ",
                   "|  ",
                   " - ",
				   "  |", 
				   " - "},
				   
				  {" - ",
                   "|  ",
                   " - ",
				   "| |", 
				   " - "},
				   
				  {" - ",
                   "  |",
                   "   ",
				   "  |", 
				   "   "},
				  {" - ",
                   "| |",
                   " - ",
				   "| |", 
				   " - "},
				   
				  {" - ",
                   "| |",
                   " - ",
				   "  |", 
				   " - "}};
void out(string &s,int n)
{
	cout<<s[0];
	for(int i=0;i<n;i++)cout<<s[1];
	cout<<s[2];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	while(cin>>n>>s)
	{
		if(n==0)break;
		for(int i=0;i<5;i++)
		{
			if(i==0||i==2||i==4)
			{
				for(int j=0;j<s.size();j++)
				{
					out(pad[s[j]-'0'][i],n);
					if(j!=s.size()-1)cout<<' ';
				}
				cout<<endl;
			}
			else for(int j=0;j<n;j++)
			{
				for(int j=0;j<s.size();j++)
				{
					out(pad[s[j]-'0'][i],n);
					if(j!=s.size()-1)cout<<' ';
				}
				cout<<endl;
			}
			//for(char j:s)cout<<pad[j-'0'][i];
		}
		cout<<endl;
	}
	return 0;
}

