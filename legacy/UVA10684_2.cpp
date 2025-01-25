#include<bits/stdc++.h>
using namespace std;
struct cmp
{
	bool operator()(int a,int b)
	{
		return a>
		b;	
	}
};
//priority_queue<int,vector<int>,cmp> les;
int a[10010],s[10010];
int main()
{
	int tmp;
	int n;
	while(cin>>n)
	{
		if(n==0)return 0;
		s[0]=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]+a[i];
		}
		int MAX=-1,_min=0;
		//les.push(0);
		for(int i=1;i<=n;i++)
		{
			if(s[i]-_min>MAX)
			{
				//MAX=s[i]-les.top();
				MAX=s[i]-_min; 
			}
			if(s[i]<_min)_min=s[i];
			//les.push(s[i]);
		}
		if(MAX>0)cout<<"The maximum winning streak is "<<MAX<<'.'<<endl;
		else cout<<"Losing streak."<<endl;
	} 
	
}

