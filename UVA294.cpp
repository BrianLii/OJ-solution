#include<bits/stdc++.h>
using namespace std;
long long np[35000];
vector<long long> pr;
void sai(long long x=34000)
{
	long long i;
	for(i=2;i*i<=x;i++)
	{
		if(!np[i])
		{
			np[i]=i;
			pr.push_back(i);
			for(long long j=i*i;j<=x;j+=i)
				if(!np[j])np[j]=i;
		}
	}
	for(;i<=x;i++)
	{
		if(!np[i])
		{
			np[i]=i;
			pr.push_back(i);	
		}
	}
}
long long cal(long long x)
{
	if(x==1)return 1;
	typedef pair<long long,long long> pii;
	vector<pii> fac;
	long long now=x;
	for(long long i:pr)
	{
		if(i*i>x)break;
		long long cnt=0;
		while(now%i==0)
		{
			now/=i;
			cnt++;
		}
		if(cnt)fac.emplace_back(i,cnt);
	}
	if(now!=1)fac.emplace_back(now,1);
	long long ans=1;
	for(auto i:fac)
	{
		ans*=i.second+1;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	sai();
	long long l,r;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		cout<<"Between "<<l<<" and "<<r<<", ";
		long long ma=0,manum;
		
		for(long long i=l;i<=r;i++)
		{
			long long tmp=cal(i);
			if(tmp>ma)
			{
				ma=tmp;
				manum=i;	
			}
		}
		cout<<manum<<" has a maximum of "<<ma<<" divisors."<<endl;
	}
	 
	return 0;
}

