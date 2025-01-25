#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
unordered_map<char,int> board;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		board.clear();
		int K;
		cin>>K;
		while(K--)
		{
			char c;
			cin>>c;
			cin>>board[c];
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

