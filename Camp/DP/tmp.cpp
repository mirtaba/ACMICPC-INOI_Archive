#include<iostream>
#include<stdio.h>
using namespace std;
int a[1010][1010]={0};
int main()
{
    int n, m, t, k;
    cin>>t;
    for(int z=1 ; z<=t ; ++z)
    {
        cin>>n>>m>>k;
        for(int i=1 ; i<=n ; ++i)
        {
            for(int j=1 ; j<=m ; ++j)
            {
                cin>>a[i][j];
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        long long int area=0, mony=0;

        for(int x=1 ; x<=n ; ++x)
        {
            for(int y=1 ; y<=m ; ++y)
            {
                for(int u=1 ; u<=x ; ++u)
                {
                    for(int v=1 ; v<=y ; ++v)
                    {
                        long long int s=a[x][y]-a[x][v-1]-a[u-1][y]+a[u-1][v-1];
                        long long int b=(x-u+1)*(y-v+1);
                        if(b>area && s<=k)
                        {
                            mony=s;
                            area=b;
                        }
                        else if(b==area && s<mony)
                        {
                            mony=s;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<z<<": "<<area<<" "<<mony<<endl;
    }
}
