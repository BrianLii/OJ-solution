#include<bits/stdc++.h>
using namespace std;
int sum[120][120],a[120][120];
int cal(int i1,int j1,int i2,int j2)
{
	return sum[i2][j2]
		-sum[i1-1][j2]
		-sum[i2][j1-1]
		+sum[i1-1][j1-1];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i][j-1]+a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]+=sum[i-1][j];
	int ma=(-127*100*102);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=i;k<=n;k++)
			{
				for(int m=j;m<=n;m++)
				{
					ma=max(ma,cal(i,j,k,m));
				}
			}
		}
	}
	cout<<ma<<endl;
	return 0;
}

