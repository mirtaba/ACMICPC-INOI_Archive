#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(LL i = n ; i < m ; i++)
#define DFOR(i,n,m) for(LL i = n ; i >= m ; i--)
#define pb push_back

const int Maxn = 1000 * 100 + 250;

typedef long long LL;

LL g[Maxn];
LL n , m , tmp , ans = 0;

int main()
{
    cin >> n >> m;
    FOR(i,0,n)
    {
        cin >> tmp;
        tmp--;
        g[tmp] ++ ;
    }
    ans = (n * (n-1)) / 2;

    FOR(i,0,m)
    {
        if(g[i]>1)
            ans -= ((g[i]*(g[i]-1)) / 2);
    }
    cout << ans << endl;
}
