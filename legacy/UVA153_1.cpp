#include<bits/stdc++.h>
using namespace std;
__int128 app[30];
__int128 jie[45];
string s;
void cal()
{
	__int128 ans=0;
	for(__int128 i=0,len=s.size();i<len;i++)
	{
		for(__int128 j=0;j<s[i]-'a';j++)
		{
			if(app[j])
			{
				app[j]--;
				__int128 tmp=jie[len-i-1];
				for(__int128 k=0;k<26;k++)
					tmp/=jie[app[k]];
				ans+=tmp;
				app[j]++;
			} 
		}
		app[s[i]-'a']--;
	}
	long long out=ans;
	cout<<setw(10)<<out+1<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	jie[0]=1;
	for(__int128 i=1;i<32;i++)jie[i]=jie[i-1]*i;
	while(cin>>s)
	{
		if(s[0]=='#')break;
		memset(app,0,sizeof(app));
		for(char c:s)app[c-'a']++;
		cal();
	}
	return 0;
}

