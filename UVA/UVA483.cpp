#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string in;
	while(getline(cin,in))
	{
		for(int i=0;i<in.size();i++)
		{
			if(in[i]==' ')
			{
				for(int j=i-1;j>=0;j--)
				{
					if(in[j]==' ')break;
					cout<<in[j];
				}
				cout<<' ';
			}
		}
		if(in[in.size()-1]!=' ')
		{
			for(int j=in.size()-1;j>=0;j--)
			{
				if(in[j]==' ')break;
				cout<<in[j];
			}
		}
		cout<<endl;
	}
	
	return 0;
}

