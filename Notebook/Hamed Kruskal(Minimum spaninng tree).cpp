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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

PII e[Maxn];
LL par[Maxn],Size[Maxn];

LL father (int x)
{
    if(par[x] == -1)
        return x;
    return par[x] = father (par[x]);
}

LL Merge (LL a, LL b)
{
    a =father (a);
    b =father (b);
    if (a==b) return 0;
    if (Size[a] > Size[b] ) swap(a,b);
    par[a]=b;
    Size[b] += Size[a];
    return weight[a][b];
}

int main()
{
	ios::sync_with_stdio(0);
	LL n,m;
	cin >> n >> m;
	FOR(i,0,m)
	{
	    cin >> e[i];
	}
	sort(e,e+m);
	FOR(i,0,m)
        res+=Merge (e[i].first,e[i].second);
    return 0;
}

