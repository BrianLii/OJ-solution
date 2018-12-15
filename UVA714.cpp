#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000];
int m,k;
bool check(ll num)
{
	ll now=0,np=k;
	for(int i=m-1;i>=0;i--)
	{
		//cout<<now<<' '<<np<<endl;
		if(now>num)return 0;
		if(np==0)return 0;
		
		if(now+p[i]<=num)now+=p[i];
		else if(now+p[i]>num)
		{
			now=p[i];
			np--;
		}
	}
	if(np==0)return 0;
	if(now>num)return 0;
	return 1;
}
void cut(ll num)
{
	vector<int> ans;
	int now=0,np=k;
	for(int i=m-1;i>=0;i--)
	{		
		if(now+p[i]<=num)now+=p[i];
		else if(now+p[i]>num)
		{
			now=p[i];
			np--;
			ans.push_back(i);
		}
	}
	reverse(ans.begin(),ans.end());
	int left=k-1-ans.size();
	ans.push_back(100000000);
	vector<int> fans;
	for(int i=0,now=0;i<m;i++)
	{
		if(left&&ans[now]>i)
		{
			fans.push_back(i);
			left--; 
		}
		else if(ans[now]==i)
		{
			fans.push_back(i);
			now++;
		}
	}
	for(int i=0,now=0;i<m;i++)
	{
		cout<<p[i];
		if(i!=m-1)cout<<' ';
		if(now<k-1&&fans[now]==i)
		{
			cout<<"/ ";
			now++;
		}
	}
	cout<<endl;
	//for(int i:ans)cout<<i<<' ';
	//cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>m>>k;
		ll sum=0;
		for(int i=0;i<m;i++)
		{
			cin>>p[i];
			sum+=p[i];
		}
		ll l=0,r=sum;
		while(l<r)
		{
			ll mid=(l+r)/2;
			if(check(mid)==1)r=mid;
			else if(check(mid)==0)l=mid+1;
		}
		cut(l);
	}
	return 0;
}

