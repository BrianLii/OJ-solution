#include<bits/stdc++.h>
using namespace std;
string s= "ertyuiop[]dfghjkl;\'cvbnm,.";
string s2="qwertyuiopasdfghjklzxcvbnm";
char ans[500];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	ans['e']='q';
	ans['r']='w';
	ans['t']='e';
	ans['y']='r';
	ans['u']='t';
	ans['i']='y';
	ans['o']='u';
	ans['p']='i';
	ans['[']='o';
	ans[']']='p';
	ans['d']='a';
	ans['f']='s';
	ans['g']='d';
	ans['h']='f';
	ans['j']='g';
	ans['k']='h';
	ans['l']='j';
	ans[';']='k';
	ans['\'']='l';
	ans['c']='z';
	ans['v']='x';
	ans['b']='c';
	ans['n']='v';
	ans['m']='b';
	ans[',']='n';
	ans['.']='m';
	while(getline(cin,in))
	{
		for(int i:in)
		{
			if(ans[i])cout<<ans[i];
			else cout<<(char)i;
		}
		cout<<endl;
	}
	
	return 0;
}

