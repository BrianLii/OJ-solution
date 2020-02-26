#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
vector<string>oa;
vector<vector<int> >sum;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	string trash;
	getline(cin,trash);
	getline(cin,trash);
	while(t--)
	{
		oa.clear();
		sum.clear();
		string in;
		while(getline(cin,in))
		{
			if(in=="")break;
			oa.push_back(in);
		}
		int n,m;
		n=oa.size();
		m=oa[0].size();
		sum.resize(n+1);
		sum[0].resize(m+1);
		for(int i=1;i<=n;i++)
		{
			sum[i].resize(m+1);
			for(int j=1;j<=m;j++)
			{
				if(oa[i-1][j-1]=='0')sum[i][j]=INT_MIN;
				else sum[i][j]=1;
				sum[i][j]+=sum[i-1][j];
				sum[i][j]+=sum[i][j-1];
				sum[i][j]-=sum[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int ii=i;ii<=n;ii++)
					for(int jj=j;jj<=m;jj++)
					{
						int tmp=sum[ii][jj];
						tmp-=sum[i-1][jj];
						tmp-=sum[ii][j-1];
						tmp+=sum[i-1][j-1];
						ans=max(ans,tmp);		
					}
		cout<<ans<<endl;
		if(t)cout<<endl;
	}
	return 0;
}

