#include<bits/stdc++.h>
using namespace std;
bool use[1000020];
int n;
bool check(int b,int c)
{
	if(b>c)swap(b,c);
	if((b+c)%2)return 0;
	return((b+c)/2<=n&&(c-b)/2<=n);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*j<=i;j++)
		{
			if(i%j==0&&check(j,i/j))
			{
				int x=i;
				int y=((j+i/j)/2);
				int z=((i/j-j)/2);
				use[x]=use[y]=use[z]=1;
			}
		}
		if(!use[i])cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}

