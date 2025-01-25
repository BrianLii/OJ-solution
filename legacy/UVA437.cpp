#include<bits/stdc++.h>
using namespace std;
int cp[][3]{{0,1,2},{1,2,0},{0,2,1}};
struct node
{
	int a[3];
	void sort()
	{
		if(a[0]>a[1])swap(a[0],a[1]);
		if(a[1]>a[2])swap(a[1],a[2]);
		if(a[0]>a[1])swap(a[0],a[1]);
	}
};
node a[100];
int dp[100][800][800];
int dfs(int l,int xL,int yL)
{
	for(int i=0;i<n*3)	
	/*if(l<0)return 0;
	int x=a[l].a[0],
		y=a[l].a[1],
		z=a[l].a[2];
	if(x<xL&&y<yL)return max(dfs(l-1,x,y)+z,dfs(l-1,xL,yL));
	else return dfs(l-1,xL,yL);*/
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int ma=0;
	for(int i=0;i<n*3;i+=3)
	{
		cin>>a[i].a[0]>>a[i].a[1]>>a[i].a[2];
		a[i].sort();
		ma=max(ma,a[i].a[2]);
		for(int j=0;j<3;j++)
		{
			a[i+j].a[0]=a[i].a[cp[j][0]];
			a[i+j].a[1]=a[i].a[cp[j][1]];
			a[i+j].a[2]=a[i].a[cp[j][2]];
		}
	}
	cout<<ma<<endl;
	cout<<dfs(n*9-1,ma+1,ma+1)<<endl;
	return 0;
}

