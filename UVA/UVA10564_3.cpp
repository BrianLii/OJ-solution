#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50][50],dp[50][50][550];
char back[50][50][550];
int N,S;
string ans;
void ini()
{
	//memset(a,0,sizeof(a));
	for(int i=0;i<49;i++)
		for(int j=0;j<49;j++)
			for(int k=0;k<520;k++)
				dp[i][j][k]=-1;
	memset(back,0,sizeof(back));
	ans="";
}
void back_t(int l,int x,int sum)
{
	//cout<<l<<' '<<x<<' '<<sum<<endl;
	if(l==0)
	{
		return;
	}
	if(l>N-1)
	{
		if(back[l][x][sum]=='L')
		{
			back_t(l-1,x-1,sum-a[l][x]);
		}
		else if(back[l][x][sum]=='R')
		{
			back_t(l-1,x,sum-a[l][x]);
		}
		else return;
	}
	else 
	{
		if(back[l][x][sum]=='L')
		{
			back_t(l-1,x,sum-a[l][x]);
		}
		else if(back[l][x][sum]=='R')
		{
			back_t(l-1,x+1,sum-a[l][x]);
		}
		else return;
	}
	//cout<<x<<endl;
	ans.push_back(back[l][x][sum]); 
}
ll dfs(int l,int x,int sum)
{
	if(dp[l][x][sum]!=-1)return dp[l][x][sum];
	if(x<=0)return dp[l][x][sum]=0;
	if(sum<0)return dp[l][x][sum]=0;
	if(l<=N-1&&x>N-l)return dp[l][x][sum]=0;
	if(l>N-1&&x>l-N+2)return dp[l][x][sum]=0;
	if(l==0)
	{
		if(sum==a[l][x])return dp[l][x][sum]=1;
		else return dp[l][x][sum]=0;
	}
	if(l>N-1)
	{
		//cout<<l<<' '<<x<<' '<<sum-a[l][x]<<' '<<sum-a[l][x]<<endl;
		ll m=dfs(l-1,x,sum-a[l][x]),n=dfs(l-1,x-1,sum-a[l][x]);
		if(n)
		{
			
			back[l][x][sum]='L';
			//cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		else if(m)
		{
			back[l][x][sum]='R';
			//cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		return dp[l][x][sum]=n+m;
	}
	else
	{
		//cout<<l<<' '<<x<<' '<<sum-a[l][x]<<' '<<x+1<<endl;
		ll m=dfs(l-1,x,sum-a[l][x]),n=dfs(l-1,x+1,sum-a[l][x]);
		if(m)
		{
			back[l][x][sum]='L';
			//cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		else if(n)
		{
			back[l][x][sum]='R';
			//cout<<l<<' '<<x<<' '<<sum<<' '<<back[l][x][sum]<<endl;
		}
		return dp[l][x][sum]=n+m;
	}
}
int main()
{
	
	while(cin>>N>>S)
	{
		ini();
		if(!N)break; 
		for(int i=N-1;i>=1;i--)
		{
			for(int j=0;j<i+1;j++)
			{
				cin>>a[i+N-1][j+1];
			}
		}
		for(int i=N-1;i>=0;i--)
		{
			for(int j=0;j<N-i;j++)
			{
				cin>>a[i][j+1];
			}
		}
		ll sum=0;
		for(int i=1;i<=N;i++)
		{
			sum+=dfs(2*N-2,i,S);
		}
		cout<<sum<<endl;
		for(int i=1;i<=N&&sum;i++)
		{
			back_t(2*N-2,i,S);
			if(ans!="")
			{
				cout<<i-1<<" ";
				for(int i=ans.size()-1;i>=0;i--)cout<<ans[i];
				break;
			}
		}
		cout<<endl;
		
	}
	return 0;
}

