#include <iostream>
using namespace std;
const int maxn=100+2;
const int maxm=100+5;
const int maxx=1<<12;
int dyn[maxn][maxx][maxm];
int main()
{
    long long count=0;
    int n,k,x,y,x1,x2,x3;
    cin>>n>>k;
    for(int i=0;i<(1<<n);i++)
    {
        x=i>>1;
        y=X&i;
        if(y>0)
        {
            y=__builtin_popcount(i);
            dyn[1][i][y]=0;
        }
        else
        {
            y=__builtin_popcount(i);
            if(y<=k)
                dyn[1][i][y]=1;
        }
    }
    if(k>25)
        cout<<"0"<<endl;
    else
    for(int i=2;i<=n;i++)
    {
        for(int t=1;t<=k;t++)
        {
            for(int j=0;j<(1<<n);j++)
            {
                y=__builtin_popcount(i);
                if(dyn[1][j][y]>0)
                    for(int l=0;l<(1<<n);l++)
                    {
                        if((l&j)==0)
                        {
                            x1=l>>1;
                            x2=l<<1;
                            if(t>=y)
                                if(x1&j==0 && x2&j==0)
                                    dyn[i][j][t]+=dyn[i-1][l][t-y];
                        }
                    }
            }
    }
    for(int i=0;i<(1<<n);i++)
        count+=dyn[n][i][k];
    cout<<count<<endl;


    return 0;
}
