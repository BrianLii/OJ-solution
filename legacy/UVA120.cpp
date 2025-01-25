#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string in;
	while(getline(cin,in))
	{
		n=0;
		stringstream ss;
		ss<<in;
		while(ss>>a[++n]);
		n--;
		vector<int> v;
		for(int i=1;i<=n;i++)
		{
			if(i!=1)cout<<' ';
			cout<<a[i];
			v.push_back(a[i]);
		}
		sort(v.begin(),v.end());
		cout<<endl;
		for(int i=n;i>=1;i--)
		{
			int p=v[i-1];
			if(a[i]==p)continue;
			for(int j=i-1;j>1;j--)
			{
				if(a[j]==p)
				{
					cout<<n-j+1<<' ';
					reverse(a+1,a+j+1);
				}	
			}
			cout<<n-i+1<<' ';
			reverse(a+1,a+i+1);
		}
		cout<<0<<endl;
	}
	return 0;
}

