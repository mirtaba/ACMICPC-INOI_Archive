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

vector <PLL> ans;
LL x,y,a,b;

int main()
{
	ios::sync_with_stdio(0);
	cin >> x >> y >> a >> b;
	for(LL i=a;i<=x;i++)
	{
	    for (LL j=b;j<=y;j++)
	    {
	        if (i > j)
	        {
	            ans.pb(mp(i,j));
	        }
	    }
	}
	cout << ans.size() << endl;
	FOR(i,0,ans.size())
	{
	    cout << ans[i].X << ' ' << ans[i].Y << endl;
	}
}
