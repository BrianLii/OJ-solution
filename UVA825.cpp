#include<bits/stdc++.h>
int n,w,cnt=1;
using namespace std;
int stp[10000][10000],p[10000],q[10000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>w>>n;
		for(int i=0;i<w;i++)
		{
			string s;
			int tmp,num;
			cin>>num;
			getline(cin,s);
			stringstream ss;
			ss.str("");
			ss.clear();
			ss<<s;
			while(ss>>tmp)
			{
				//cout<<num-1<<' '<<tmp-1<<endl;
				stp[num-1][tmp-1]=cnt;
			}
		}
		int *now=p,*last=q;
		last[0]=0;
		for(int i=1;i<n;i++)
		{
			if(stp[0][i]==cnt)last[i]=0;
			last[i]=last[i-1];
		}
		int nowl=0;
		while(nowl<=w-1)
		{
			if(stp[nowl][0]==cnt)now[0]=0;
			else now[0]=1;
			for(int i=1;i<n;i++)
			{
				if(stp[nowl][i]==cnt)now[i]=0;
				else now[i]=last[i]+now[i-1];
			}
			//for(int i=0;i<n;i++)cout<<now[i]<<' ';
			//cout<<endl;
			swap(last,now);
			nowl++;
		}
		if(t==0)cout<<last[n-1]<<endl;
		else cout<<last[n-1]<<endl<<endl;
		cnt++;
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
	}
	
}

