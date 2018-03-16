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
#define FOR(i,a,b) for(int i=a;i<b;i++)
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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL par[Maxn],size[Maxn],N,M,tmp1,tmp2,tmp,ans;
pair <pair<LL,LL> ,LL > E[Maxn];

LL father (int x)
{
    if (par[x] != -1)
        return par[x] = father (par[x]);
    else
        return x;
}

bool cmp (pair <pair<LL,LL> ,LL > a, pair <pair<LL,LL> ,LL > b)
{
    return (a.Y < b.Y) ;
}

LL merge (LL a, LL b, LL jj)
{
    a = father(a);
    b=  father(b);
    if (a == b)
        return 0;
    if (size[a] > size[b]) swap (a,b);
    par[a]=b;
    size[a]+=size[b];
    return E[jj].Y ;
}

int main()
{
	ios::sync_with_stdio(0);
	MEM(par,0xFF);
    cin >> N >> M;
    FOR(i,0,M)
    {
        cin >> tmp1 >> tmp2 >> tmp;
        E[i]=mp(mp(tmp1,tmp2),tmp);
        size[tmp1]=1;
        size[tmp2]=1;
    }
    ans=0;
    sort(E,E+M,cmp);
    FOR(i,0,M)
    {
        ans+=merge(E[i].X.X,E[i].X.Y,i);
    }
    cout << ans << endl;

}
