#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <cmath>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const LL INF = (LL) 1e18;

LL d[Maxn],mark[Maxn],N,M,tmp1,tmp2,tmp,par[Maxn];
vector <PLL> Graph[Maxn];
vector <LL> ans;
set <PLL> S;

int main()
{
    cin >> N >> M;
    MEM(d,0x1F);
    d[N]=INF;
    for (int i=0;i<M;i++)
    {
        cin >> tmp1 >> tmp2>> tmp;
        Graph[tmp1].pb(mp(tmp2,tmp));
        Graph[tmp2].pb(mp(tmp1,tmp));
    }
    d[1]=0;
    S.insert(mp(d[1],1));
    while(S.size())
    {
        int u=S.begin() -> Y;
        mark[u]=true;
        S.erase(mp(d[u],u));
        for (int i=0;i<Graph[u].size();i++)
        {
            int x=Graph[u][i].X;
            if(d[x]>d[u]+Graph[u][i].Y && !mark[x])
            {
                par[x]=u;
                S.erase(mp(d[x],x));
                d[x]=d[u]+Graph[u][i].Y;
                S.insert(mp(d[x],x));
            }
        }
    }
    tmp=N;
    //cerr << d[N-2] << endl;
    if (d[N]==INF)
    {
        cout << -1 << endl;
    }
    else
    {
        while(tmp!=1)
        {
            ans.pb(tmp);
            tmp=par[tmp];
        }
        ans.pb(1);
        reverse(ans.begin(),ans.end());
        FOR(0,ans.size())
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;

}

