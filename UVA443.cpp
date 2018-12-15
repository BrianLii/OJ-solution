#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> num;
ll a[]{2LL,3LL,5LL};
void dfs(int x,ll n)
{
	if(x==3)
	{
		if(n<0)return;
		num.push_back(n);
		return;
	}
	for(int i=0;i<50;i++)
	{
		dfs(x+1,n*pow(a[x],i));
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	dfs(0,1);
	sort(num.begin(),num.end());
	int tmp;
	while(cin>>tmp)
	{
		if(tmp==0)return 0;
		cout<<"The "<<tmp;
		if(tmp%10==1&&tmp%100!=11)cout<<"st";
		else if(tmp%10==2&&tmp%100!=12)cout<<"nd";
		else if(tmp%10==3&&tmp%100!=13)cout<<"rd";
		else cout<<"th";
		cout<<" humble number is "<<num[tmp-1]<<'.'<<'\n';
	}
	return 0;
}

