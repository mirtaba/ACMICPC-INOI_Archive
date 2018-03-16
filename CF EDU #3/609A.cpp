#include <bits/stdc++.h>
using namespace std;

#define FOR(i,n,m) for(int i = n ; i < m ; i++)
#define DFOR(i,n,m) for(int i = n ; i >= m ; i--)
#define pb push_back

vector <int> in;
int n , m , tmp , ans = 0;

int main()
{
    cin >> n;
    cin >> m;
    FOR(i,0,n)
    {
        cin >> tmp;
        in.pb(tmp);
    }
    sort(in.begin(),in.end());
    ans = 0;
    DFOR(i,in.size()-1,0)
    {
        m-= in[i];
        ans++;
        if(m <= 0) break;
    }
    cout << ans << endl;
}
