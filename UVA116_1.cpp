#include<iostream>
#include<cstring>
#include<algorithm>
#define UP -1
#define MID 0
#define DOWN 1
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
int hi,wi;
ll a[200][200],dp[200][200];
int used[200][200],track[200][200],cnt=0;
long long _min(long long l,long long m, long long r)
{
	return min(l,min(m,r));
}
void back_track(int now)
{
	for(int i=wi-1;i>0;i--)
	{
		cout<<now+1<<' ';
		//cout<<track[now][i]<<' ';
		if(track[now][i]==UP)now=(now-1+hi)%hi;
		else if(track[now][i]==DOWN)now=(now+1)%hi;
	}
	cout<<now+1;
	cout<<endl;
}
ll dfs(int l,int x)
{
	if(used[l][x]==cnt)return dp[l][x];
	used[l][x]=cnt;
	if(x==0)
	{
		//cout<<a[l][x]<<endl
		return a[l][x];
	}
	pii tmp[3];
	ll  up=dfs((l-1+hi)%hi,x-1),
		mid=dfs(l,x-1),
		down=dfs((l+1)%hi,x-1);
	ll __min=_min(up,down,mid);
	tmp[0]=make_pair(up,(l-1+hi)%hi);
	tmp[1]=make_pair(mid,l);
	tmp[2]=make_pair(down,(l+1)%hi);
	sort(tmp,tmp+3);
	/*for(int i=0;i<3;i++)
	{
		cout<<tmp[i].first<<' '<<tmp[i].second<<endl;
	}*/
	for(int i=0;i<3;i++)
	{
		if(__min==tmp[i].first&&tmp[i].second==(l-1+hi)%hi)
		{
			track[l][x]=UP;
			break;
		}
		else if(__min==tmp[i].first&&tmp[i].second==l)
		{
			track[l][x]=MID;
			break;
		}
		else if(__min==tmp[i].first&&tmp[i].second==(l+1)%hi)
		{
			track[l][x]=DOWN;
			break;
		}
	}
	/*if(__min==up)track[l][x]=UP;
	else if(__min==mid)track[l][x]=MID;
	else if(__min==down)track[l][x]=DOWN; 
	//cout<<_min(up,mid,down)+a[l][x]<<endl;

	/*if(__min==up)track[l][x]=UP;
	else if(__min==mid)track[l][x]=MID;
	else if(__min==down)track[l][x]=DOWN;*/
	return dp[l][x]=__min+a[l][x];
}
int main() {
	while(cin>>hi>>wi)
	{
		cnt++;
		memset(track,0,sizeof(track));
		for(int i=0;i<hi;i++)
		{
			for(int j=wi-1;j>=0;j--)
			{
				cin>>a[i][j];
			}
		}
		for(int i=0;i<hi;i++)
		{
			dp[i][0]=a[i][0];
			//used[i][0]=cnt;
		}
		long long MIN=dfs(0,wi-1),MIN_num=0;
		for(int i=1,tmp;i<hi;i++)
		{
			tmp=dfs(i,wi-1);
			if(tmp<MIN)
			{
				MIN=tmp;
				MIN_num=i;
			}
		}
		back_track(MIN_num);
		cout<<MIN<<endl;
	}
	
	
	return 0;
}

