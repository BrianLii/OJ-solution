#include<bits/stdc++.h>
#define mod INT_MAX
using namespace std;
typedef long long ll;
ll fac[10000040];
inline ll qpow(ll a,ll b)
{
    if(!a)return 0;
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
inline ll devide(ll x,ll y)
{
    return x*qpow(y,mod-2)%mod;
}
int main() {
    
    fac[0]=1;
    for(ll i=1;i<=10000010;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
    }
    ll n,m;
    while(cin>>n>>m)
    {
    	if(n==0&&m==0)return 0 ;
    	if(m==0)cout<<1<<endl;
    	else if(m==1)cout<<n<<endl;
    	else if(m==2)cout<<(n*(n-1))/2;
    	else if(m==3)cout<<(n*(n-1)*(n-2))/3;
    	else
    	{
			ll ans=devide(devide(fac[n],fac[n-m]),fac[m]);
			cout<<ans<<endl;
		}
	}    
    return 0;
}
