#include<bits/stdc++.h>
using namespace std;
struct big
{
	vector<int> v;
};
void add(big &num,int base)
{
	big ans;
	ans.v.resize(num.v.size()+1);
	
	int carr=0;
	for(int i=0,j=num.v.size()-1,len=num.v.size();i<len;i++,j--)
	{
		ans.v[i]=num.v[i]+num.v[j]+carr;
		carr=ans.v[i]/base;
		ans.v[i]%=base;
	}
	ans.v.back()=carr;
	if(ans.v.back()==0)ans.v.pop_back();
	num=ans;
}
bool check(const big &num)
{
	bool flag=1;
	for(int i=0,j=num.v.size()-1,len=num.v.size();i<len/2&&flag;i++,j--)
	{
		flag&=(num.v[i]==num.v[j]);
	}
	return flag;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	while(cin>>s)
	{
		
		big num;
		num.v.resize(s.size());
		for(int i=0,j=s.size()-1,len=s.size();i<len;i++,j--)
		{
			if(s[j]<='Z'&&s[j]>='A')num.v[i]=s[j]-'A'+10;
			else num.v[i]=s[j]-'0';
		}
		const big start=num;
		for(int base=15;base>=2;base--)
		{
			if(base!=15)cout<<' ';
			big now=start;
			bool ill=0;
			for(int i:num.v)
				if(i>=base)
				{
					cout<<"?";
					ill=1;
					break;
				}
			if(ill)continue;
			for(int i=0;i<=100;i++)
			{
				if(check(now))
				{
					cout<<i;
					break;	
				}
				add(now,base);
			}
		}
		cout<<endl;
	}
	return 0;
}

