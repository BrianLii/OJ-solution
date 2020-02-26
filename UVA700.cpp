#include<iostream>
using namespace std;
int a[30],b[30],y[30];
//conv = y[i]%(b[i]-a[i])+a[i]
bool check(int ny,int i)
{
	return (ny-a[i])%(b[i]-a[i])+a[i]==y[i];
}
int main() 
{
    int n;
    int cnt=0;
    while(cin>>n)
    {
        if(!n)return 0;
        cout<<"Case #"<<++cnt<<":\n";
        int ma=0;
        for(int i=0;i<n;i++)
        {
            //b[i] will go to a[i]
            cin>>y[i]>>a[i]>>b[i];
            ma=max(ma,a[i]);
        }
        bool suss=0;
        int ans;
        for(int i=ma;i<10000&&!suss;i++)
        {
            bool fail=0;
            for(int j=0;j<n&&!fail;j++)
            {
                if(!check(i,j))fail=1;
            }
            if(!fail)
            {
                suss=1;
                ans=i;
                break;
            }
        }
        if(suss)cout<<"The actual year is "<<ans<<'.'<<endl;
        else cout<<"Unknown bugs detected."<<endl;
        cout<<endl;
    }
    
    return 0;
}
/*
2
1941 1900 2000
2005 1904 2040
2
1998 1900 2000
1999 1900 2000
0
*/
