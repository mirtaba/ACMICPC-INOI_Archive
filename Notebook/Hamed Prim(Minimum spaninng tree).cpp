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
const LL INFI= ~0u/2;//u means unsigned

int main()
{
	cin >> n >> m;
	FOR(i,0,m);
	{
	    int x,y,c;
	    cin >> x>> y >>c;
	    x--;
	    y--;
	    a[x].pb(y);
	    a[y].pb(x);
	    w[x].pb(c);
	    w[y].pb(c);
	}

	int res=0;
	set<PII> s;
	d[0]=0;
	s.insert(mp(0,0));
    while(s.size())
    {
        PII x=*s.begin;
        s.erase(x);
        res += x.first;
        mark[x.second]= 1;
        FOR(j,0,a[x.second].size)
        {
            int v=a[x.second][j];
            if (!mark[v])
            {
                if(d[v] > w[x.second][j])
                {
                    s.erase (mp(d[v],v));
                    d[v]= w[x.sescond][j];
                    s.insert(mp(d[v],v));
                }
            }
        }
    }
    cout << res << endl;
}
