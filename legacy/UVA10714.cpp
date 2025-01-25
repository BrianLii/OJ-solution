#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
//a=max dis ,b=min dis
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int l,n;
		cin>>l>>n;
		int mi=0,ma=0;
		int tmp;
		for(int i=0;i<n;i++)
		{
			cin>>tmp;
			ma=max(ma,max(tmp,l-tmp));
			mi=max(mi,min(tmp,l-tmp));
		}
		cout<<mi<<' '<<ma<<endl;
	}
	return 0;
}

