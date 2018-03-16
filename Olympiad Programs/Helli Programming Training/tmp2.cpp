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
    dyn[n][Max]=1;
}

int make(int input,int lastdigit)
{
    if (lastdigit==0)
    {
        return (num[input]<k)? -1:((((Max>>1) & input)<<1)+lastdigit);
    }
    else
    {
        return ((num[input]+1)<k)? -1:((((Max>>1) & input)<<1)+lastdigit);

    }
}

int main()
{
    cin >> n >> m >> k;
    long long temp=(Max>>1);
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
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<=Max ; j++)
        {
            x=make(j,0);
            if(x!=(-1))
            {
                dyn[i][j]+=dyn[i+1][x];
            }
            dyn[i][j]+=dyn[i+1][make(j,1)];
        }
    }
    unsigned long long tot=0;
    for(int i=0 ; i<=Max ; i++)
    {
        tot+=dyn[0][i];
    }
    cout << tot << endl;
    return 0;
}
