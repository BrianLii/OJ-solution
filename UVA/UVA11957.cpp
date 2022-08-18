#include<bits/stdc++.h>
#define MOD 1000007
//#include<vector>
//#include<queue>
//#include<algrithm>
//#include<cmath>
//#include<iostream>
using namespace std;
int num[120][120];
string board[120];
int main()
{
	int t;
	cin>>t;
	for(int cnt=1;cnt<=t;cnt++)
	{
		//cout<<t<<endl;
		int l,p,n;
		cin>>n;
		if(n==1)
		{
			cout<<1;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			bool flag=0;
			cin>>board[i];
			board[i]="  "+board[i];
			for(int j=2;j<=n+1;j++)
			{
				if(board[i][j]=='W')
				{
					l=i;
					p=j;
					flag=1;
				}
			}
			//if(flag)break;
		}
		num[l][p]=1;
		for(int i=2;i<=n+1;i++)
		{
			if(board[l-1][i]!='B')
				num[l-1][i]=num[l][i-1]+num[l][i+1];
		}
		int nowl=l-2;
		while(nowl>=0)
		{
			for(int i=2;i<=n+1;i++)
			{
				if(board[nowl][i]!='B')
				{
					num[nowl][i]=num[nowl+1][i-1]+num[nowl+1][i+1];
					num[nowl][i]%=MOD;
					if(board[nowl+1][i-1]=='B')
						num[nowl][i]+=num[nowl+2][i-2];
					num[nowl][i]%=MOD;
					if(board[nowl+1][i+1]=='B')
						num[nowl][i]+=num[nowl+2][i+2];
					num[nowl][i]%=MOD;
				}
			}
			nowl--;
		}
		int sum=0;
		for(int i=2;i<=n+1;i++)
		{
			sum+=num[0][i];
			sum%=MOD;
		}
		cout<<"Case "<<cnt<<": "<<sum<<endl;
		for(int i=0;i<102;i++)
		{
			board[i]="";
		}
		//memset(board,0,sizeof(board));
		memset(num,0,sizeof(num));
	}
	return 0;
}

