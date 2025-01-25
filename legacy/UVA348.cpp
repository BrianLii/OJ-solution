#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<int,int> pii;
pii arr[30];
int cal(pii a,pii b){
	//計算重複的值 
	int x1=a.first,x2=b.first,y1=a.second,y2=b.second;
	if(x1==y1)return x1;
	if(x1==y2)return x1;
	if(x2==y1)return x2;
	if(x2==y2)return x2;	
}
int cal2(pii a,pii b){
	//計算乘法次數 
	long long  x1=a.first,x2=b.first,y1=a.second,y2=b.second;
	return x1*x2*y2*y1/cal(a,b);
}
pii cal_s(pii a,pii b){
	//計算乘完的矩陣大小 
	int x1=a.first,x2=b.first,y1=a.second,y2=b.second;
	if(x1==y1)return pii(x2,y2);
	if(x1==y2)return pii(x2,y1);
	if(x2==y1)return pii(x1,y2);
	if(x2==y2)return pii(x1,y1);	
}
struct ans
{
	pii p;
	int t;
	ans(){}
	ans(pii a,int b){p=a;t=b;}	
};
/*pii dfs(int l,int r)
{
	if(l==r)return arr[l];
	int mi=0x3f3f3f3e;
	int ma_num;
	for(int i=l;i<r;i++)
	{
		int tmp=cal2(dfs(l,i),dfs(i+1,r));
		if(tmp<mi)
		{
			mi=tmp;
			ma_num=i;
		}
	}
	if(l==0&&r==n-1)cout<<cal2(dfs(l,ma_num),dfs(ma_num+1,r))<<endl;
	return cal_s(dfs(l,ma_num),dfs(ma_num+1,r));
}*/
int path[25][25];
ans dp[25][25];
int cnt;
int used[25][25];
ans dfs(int l,int r)
{
	if(used[l][r]==cnt)return dp[l][r];
	used[l][r]=cnt;
	if(l==r)return dp[l][r]=ans(arr[l],0);
	int mi=0x3f3f3f3e;
	ans al,ar;
	for(int i=l;i<r;i++)
	{
		ans pl=dfs(l,i),
			pr=dfs(i+1,r);
		int tmp=cal2(pl.p,pr.p)+pl.t+pr.t;
		if(tmp<mi)
		{
			path[l][r]=i;
			mi=tmp;
			al=pl;ar=pr;
		}
	}
	//if(l==0&&r==n-1)cout<<al.t+ar.t+cal2(al.p,ar.p)<<endl;
	return dp[l][r]=ans(cal_s(al.p,ar.p),al.t+ar.t+cal2(al.p,ar.p));
}
void rec(int l,int r)
{
	if(l==r)
	{
		cout<<'A'<<l+1;
		return;
	}
	if(r==l+1)
	{
		cout<<"(A"<<l+1<<" x A"<<r+1<<')';
		return;
	}
	/*cut[path[l][r]]+=t++;
	cout<<path[l][r]<<endl;*/
	cout<<'(';
	rec(l,path[l][r]);
	cout<<" x ";
	rec(path[l][r]+1,r);
	cout<<')';
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n)
	{
		if(!n)return 0;
		cnt++;
		cout<<"Case "<<cnt<<": ";
		for(int i=0,a,b;i<n;i++)
		{
			cin>>a>>b;
			arr[i]=pii(a,b);
		}
		dfs(0,n-1);
		rec(0,n-1);
		//for(int i=0;i<=n;i++)cout<<cut[i]<<' ';
		cout<<endl;
		memset(path,0,sizeof(path));
	}
	return 0;
}
