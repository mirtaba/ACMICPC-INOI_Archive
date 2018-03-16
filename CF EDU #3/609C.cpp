#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(LL i = n ; i < m ; i++)
#define DFOR(i,n,m) for(LL i = n ; i >= m ; i--)
#define pb push_back

const int Maxn = 1000 * 100 + 250;

typedef long long LL;

LL in[Maxn];
LL n , m = 0 , tmp , ans = 0 , total = 0 , goal = 0;

int main()
{
    cin >> n;
    FOR(i,0,n)
    {
        cin >> tmp;
        in[tmp]++;
        m = max (m , tmp);
    }
    int i = 0;
    int j = m;


    while(in[i]==0) i++;
    while(in[j]==0) j--;

    while ((j-i) > 1)
    {
        int mini = min (in[i], in[j]);

        ans += mini;

        in[i+1]+=mini;
        in[i]-=mini;
        in[j-1]+=mini;
        in[j]-=mini;

        while(in[i]==0) i++;
        while(in[j]==0) j--;

    }

    cout << ans << endl;
}
