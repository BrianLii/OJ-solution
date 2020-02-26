#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x1,y1,x2,y2;
	while(cin>>x1>>y1>>x2>>y2)
	{
		//shie
		if(x2==x1&&y2==y1)cout<<0<<endl;
		else if(x2==x1||y2==y1||abs(x1-x2)==abs(y1-y2))
		{
			cout<<1<<endl;
		}
		else cout<<2<<endl;
		//two step 
	}
	return 0;
}

