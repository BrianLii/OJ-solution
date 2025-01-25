#include<bits/stdc++.h>
//#define endl '\n'
#define int long long
#define X first
#define Y second
#define sz(x) ((int)x.size())
#define CLR(x,y) memset(x,y,sizeof(x))
using namespace std;
typedef pair<int,int> pii;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2,s3,s4;
	bool flag=0;
	while(cin>>s1>>s2>>s3>>s4)
	{
		if(flag)cout<<endl;
		flag=1;
		int app[26]={0};
		memset(app,-1,sizeof(app));
		for(int i=0;i<s2.size();i++)
			if(app[s2[i]-'A']==-1)app[s2[i]-'A']=i;
		int p1=-1,p2=-1;
		for(int i=0;i<s1.size();i++)
		{
			if(~app[s1[i]-'A'])
			{
				p1=i;
				p2=app[s1[i]-'A'];
				break;
			}
		}
		memset(app,-1,sizeof(app));
		for(int i=0;i<s4.size();i++)
			if(app[s4[i]-'A']==-1)app[s4[i]-'A']=i;
		int p3=-1,p4=-1;
		for(int i=0;i<s3.size();i++)
		{
			if(~app[s3[i]-'A'])
			{
				p3=i;
				p4=app[s3[i]-'A'];
				break;
			}
		}
		if(p1==-1||p2==-1||p3==-1||p4==-1)
		{
			cout<<"Unable to make two crosses"<<endl;
			continue;
		}
		int ma=max(p2,p4);
		for(int i=0,j=p2-ma,k=p4-ma;i<ma;i++,j++,k++)
		{
			cout<<setw(p1)<<"";
			if(j>=0)cout<<s2[j];
			else cout<<' ';
			if(k>=0)
			{
				cout<<"   ";
				cout<<setw(sz(s1)-p1-1)<<"";
				cout<<setw(p3)<<"";
				cout<<s4[k];
			}
			cout<<endl;
		}
		cout<<s1<<"   "<<s3;
		cout<<endl;
		ma=max(sz(s2)-p2-1,sz(s4)-p4-1);
		for(int i=0,j=p2+1,k=p4+1;i<ma;i++,j++,k++)
		{
			cout<<setw(p1)<<"";
			if(j<sz(s2))cout<<s2[j];
			else cout<<' ';
			if(k<sz(s4))
			{
				cout<<"   ";
				cout<<setw(sz(s1)-p1-1)<<"";
				cout<<setw(p3)<<"";
				cout<<s4[k];
			}
			cout<<endl;
		}
	}
	return 0;
}

