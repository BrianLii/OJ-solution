#include<bits/stdc++.h>
#define INF INT_MAX
#define endl '\n'
using namespace std;
vector<long long> pri[20][20];
int de[20][20];
long long dp[20][1020];
/*
dp[i][j] ->stay in city [i] on day[j]
           cost dp[i][j]
*/              
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	int cnt=0;
	while(cin>>n>>k)
	{
		cnt++;
		memset(dp,0,sizeof(dp));
		memset(de,0,sizeof(de));
		for(int i=0;i<19;i++)
			for(int j=0;j<19;j++)
				pri[i][j].clear();
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				cin>>de[i][j];
				for(int k=0,tmp;k<de[i][j];k++)
				{
					cin>>tmp;
					if(tmp==0)pri[i][j].push_back(INF);
					else pri[i][j].push_back(tmp);
				}
			}
		}
		for(int i=2;i<=n;i++)dp[i][0]=INF;
		dp[1][0]=0;
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				long long mi=INF;
				for(int m=1;m<=n;m++)
				{
					if(m==j)continue;
					mi=min(mi,dp[m][i-1]+
						   pri[m][j][(i-1)%de[m][j]] 
						   );
				}
				dp[j][i]=mi;
			}
			
		}
		cout<<"Scenario #"<<cnt<<endl;
		if(dp[n][k]>1e9)cout<<"No flight possible."<<endl;
		else cout<<"The best flight costs "<<dp[n][k]<<'.'<<endl;
		cout<<endl;
	}
	return 0;
}
/*
3 17
11 115 83 15 0 108 61 148 192 129 99 13
20 0 161 24 115 0 148 20 76 29 141 0 77 47 0 194 0 196 15 194 161
17 0 179 96 80 65 0 188 44 116 0 147 25 0 197 47 20 0
12 95 133 36 80 152 182 158 0 119 0 0 189
15 15 192 0 0 0 157 0 91 0 50 198 99 177 27 84
2 172 180
10 8
26 160 29 183 0 92 142 100 46 73 165 144 193 88 36 48 93 10 36 124 54 0 0 0 0 0 51
10 108 48 144 0 0 85 179 1 0 126
16 70 83 34 0 105 173 109 131 122 145 0 63 31 0 0 7
22 165 0 200 152 11 196 5 163 61 0 43 0 128 76 86 49 94 30 153 23 172 0
*/
