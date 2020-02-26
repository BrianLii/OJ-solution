#include<bits/stdc++.h>
#define MOD 34943
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		if(s=="#")return 0;
		long long hash=0;
		for(char i:s)
		{
			hash=((hash<<8)+i)%MOD;
		}
		hash=(hash<<16)%MOD;
		long long CRC=(MOD-hash)%MOD;
		string ans;
		for(int i=0;i<4;i++)
		{
			int tmp=CRC%16;
			if(tmp<=9&&tmp>=0)ans+=tmp+'0';
			else ans+=tmp-10+'A';
			CRC/=16;
		}
		cout<<ans[3]<<ans[2]<<' '<<ans[1]<<ans[0]<<endl;
	}
	return 0;
}

