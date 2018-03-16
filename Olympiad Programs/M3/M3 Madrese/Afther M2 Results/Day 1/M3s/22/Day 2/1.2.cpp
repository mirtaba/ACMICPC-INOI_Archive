#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define pf push_front
#define FOR(i,s,f) for (int i=s;i<f;i++)

typedef long long LL ;
typedef  pair <int ,int > PII;
typedef  pair <LL , LL >  PLL;


const int Mod  = 1000*1000*1000 +9;
const int Del = 11117;
const int Maxn = Del*Del +25;

int pr[Maxn];


int main()
{
    ios::sync_with_stdio(0);
    FOR(i,0,Maxn)
    {
        int j=1;
        while( (i/(1<<j)) >0)
        {
            pr[i]= max(pr[i],(i/(1<<j))*((i/(1<<j))+1) );
            j++;
        }
    }
    cout << pr[2] << ' ' << pr[4] << endl;
}
