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

const int Maxn = 1000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL par[Maxn],size[Maxn],N,M,tmp,tmp1,tmp2,ans;
vector <pair <LL,PLL> > G;

LL father (int x)
{
    if(par[x] == -1)
        return x;
    return par[x] = father (par[x]);
}

LL merge (pair <LL,PLL> l)
{
    LL a=l.Y.X;
    LL b=l.Y.Y;
    a =father (a);
    b =father (b);
    if (size[a]==0) size[a]=1;
    if (size[b]==0) size[b]=1;
    if (a==b) return 0;
    if (size[a] > size[b] ) swap(a,b);
    par[a]=b;
    size[b] += size[a];
    return l.X;
}

int main()
{
	ios::sync_with_stdio(0);
	MEM(par,0xFF);
	cin >> N >> M;
	FOR (i,1,N+1)
	{
	    cin >> tmp;
	    G.pb(mp(tmp,mp(0,i)));
	}
	FOR (i,1,M+1)
	{
	    cin >> tmp1 >> tmp2 >> tmp;
	    G.pb(mp(tmp,mp(tmp1,tmp2)));
	}
	sort (G.begin(),G.end());
	FOR(i,0,G.size())
	{
	    ans+=merge(G[i]);
	}
	cout << ans << endl;

}
