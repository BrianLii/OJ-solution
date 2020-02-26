#include<bits/stdc++.h>
using namespace std;
int app[30];
int jie[45];
string s;
int cal()
{
	int ans=0;
	for(int i=0;i<s.size(;i++)
	{
		cout<<i<<endl;
		for(int j=0;j<s[i]-'a';j++)
		{
			if(app[j])
			{
				app[j]--;
				int tmp=jie[s.size(-i-1];
				for(int k=0;k<26;k++)
					tmp/=jie[app[k]];
				ans+=tmp;
				app[j]++;
			} 
		}
		app[s[i]-'a']--;
	}
	cout<<ans+1<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	jie[0]=1;
	for(int i=1;i<32;i++)jie[i]=jie[i-1]*i;
	while(cin>>s)
	{
		memset(app,0,sizeof(app));
		for(char c:s)app[c-'a']++;
		int ans=0;
		cout<<endl;
		cal();
	}
	return 0;
}

