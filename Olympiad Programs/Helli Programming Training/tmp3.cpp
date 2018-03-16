#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const unsigned long long N=60+10, M=(1<<15)+10;
unsigned long long dyn[N][M], Max, num[M], n, m, k;

void makeset()
{
    Max=(1 << (m-1) )-1;
    for(int i=0 ; i<=Max ; i++)
    {
        unsigned long long temp=i;
        while(temp!=0)
        {
            if(temp%2==1)
                num[i]++;
            temp/=2;
        }
    }
    dyn[0][Max]=1;
}

int make(int x, int y)
{
    if(y==1)
    {
        if(num[x]+1<k)
            return -1;
    }
    else
    {
        if(num[x]<k)
            return -1;
    }
    return ((((Max>>1) & x)<<1)+y);
}

int main()
{
    cin >> n >> m >> k;
    if(k==0)
    {
        unsigned long long r=(1LL<<n);
        cout << r << endl;
        return 0;
    }
    if(k==m)
    {
        cout << 1 << endl;
        return 0;
    }
    int x;
    makeset();
    long long temp=(Max>>1);
    while(temp)
    {
        cout << temp%2;
        temp=(temp>>1);
    }
    cout << endl;
    for(int i=1 ; i<=n ; i++)
    {
        for(int j=0 ; j<=Max ; j++)
        {
            x=make(j,0);
            if(x!=(-1))
            {
                dyn[i][j]+=dyn[i-1][x];
            }
            dyn[i][j]+=dyn[i-1][make(j,1)];
        }
    }
    unsigned long long tot=0;
    for(int i=0 ; i<=Max ; i++)
    {
        tot+=dyn[n][i];
    }
    cout << tot << endl;
    return 0;
}
