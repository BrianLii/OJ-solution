#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
using namespace std;
int board[10000];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(board,0,sizeof(board));
		int K;
		cin>>K;
		cin.get();
		while(K--)
		{
			char c;
			c=cin.get();
			cin>>board[c];
			cin.get();
			//cout<<'\''<<c<<'\''<<' '<<board[c]<<endl;
		} 
		int M;
		cin>>M;
		string s;
		getline(cin,s);
		int sum=0;
		while(M--)
		{
			getline(cin,s);
			for(auto i:s)
			{
				sum+=board[i];
			}
		}
		cout<<sum/100<<'.';
		cout<<setfill('0')<<setw(2)<<sum%100<<'$'<<endl;
	}
	return 0;
}

