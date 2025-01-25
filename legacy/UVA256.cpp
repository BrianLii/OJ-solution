#include<bits/stdc++.h>
using namespace std;
vector<int> v[10];
bool check(int x)
{
	cout<<__lg(100)/__lg(2)<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<check(3025)<<endl;
	for(int i=2;i<=8;i+=2)
	{
		cout<<i<<" : "<<endl;
		for(int j=0;j<pow(10,i);j++)
		{
			if(check(j))cout<<j<<' ';			
		}
		cout<<endl;
	}
	int n;
	while(cin>>n)
	{
		
	}
	return 0;
}

