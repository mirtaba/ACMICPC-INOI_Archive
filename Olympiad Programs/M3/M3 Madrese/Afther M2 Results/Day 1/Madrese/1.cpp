#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
#define FOR(i,s,f) for (int i=s;i<=f;i++)

typedef long long LL ;
typedef  pair <int ,int > PII;
typedef  pair <LL , LL >  PLL;

const int Maxn = 1000*1000 +25;
const int Mod  = 1000*1000*1000 +9;

LL d[Maxn],D[Maxn];

int main()
{
    ios::sync_with_stdio(0);
    D[0]=1;
    D[1]=1;
    d[1]=1;
    d[2]=2;
    d[3]=3;
    d[4]=5;
    FOR(i,2,Maxn)
    {
        FOR(j,1,5)
        {
            if(i>=j)
                (D[i]+=(LL)(d[j]*D[i-j]) ) %= Mod;
        }
    }
    cout << D[1000*1000] << endl;


}
