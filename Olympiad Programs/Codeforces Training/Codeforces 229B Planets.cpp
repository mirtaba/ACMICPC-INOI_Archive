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

vector <int> a[Maxn], w[Maxn];
set <int> s[Maxn];
set <PII> best;
int d[Maxn];
bool mark[Maxn];
LL n,m,x,y,c,dis,v;

int main()
{
	ios::sync_with_stdio(0);
    cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> c;
		x--;
		y--;
		a[x].push_back (y);
		a[y].push_back (x);
		w[x].push_back (c);
		w[y].push_back (c);
	}
	for (int i = 0; i < n; i++) {
		int k, v; cin >> k;
		for (int j = 0; j < k; j++)
			cin  >> v, s[i].insert (v);
	}
    // I Love Assassin's Creed III
	MEM(d,-1);
	d[0]=0;
	best.insert(PII(d[0],0));
	while(best.size())
	{
        v=best.begin() -> Y;
	    best.erase(PII(d[v],v));
	    dis=d[v];
        while(s[v].count(dis))
            dis++;
        for (int j = 0; j < a[v].size(); j++) {
			int u = a[v][j];
			if (!mark[u])
				if (d[u] == -1 || d[u] > dis + w[v][j]) {
					best.erase (PII (d[u], u));
					d[u] = w[v][j] + dis;
					best.insert (PII (d[u], u));
				}
		}

	}
	cout << d[n - 1] << endl;

	return 0;

}
