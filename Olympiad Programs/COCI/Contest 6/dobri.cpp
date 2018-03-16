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
#define FOR(i,a,b) for(LL i=a;i<b;i++)
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

const int Maxn = 7*100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

short mark[Maxn];
LL N,in[Maxn/300],maxe,mine,ans;
LL C=(3*(1e5+10));

int main()
{
    mine=3*C;
    MEM(mark,0x1F);
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,N)
	{
	    cin >> in[i];in[i]+=C;
	    cerr << in[i] << endl;
	    mine=MIN(in[i],mine);
	    maxe=MAX(in[i],maxe);
	}
	cerr << mine << ' ' << maxe << endl;
	FOR(i,0,N)
	{
	    mark[in[i]]=1;
        FOR(j,mine-1,maxe+1)
        {
            if (mark[j]>0 && mark[j]<3)
            {
                mark[j+in[i]]=MIN(mark[j]+1,mark[j+in[i]]);
                mine=MIN(mine,j+in[i]);
                maxe=MAX(maxe,j+in[i]);
                cerr << mine << ' ' << maxe  << ' '<< j << endl;
            }
        }
        cerr << 'H' << endl;
        FOR(j,mine-1,maxe+1)
        {
            if (mark[j]>0 && mark[j]<3)
            {
                mark[j+in[i]]=MIN(mark[j]+1,mark[j+in[i]]);
                mine=MIN(mine,j+in[i]);
                maxe=MAX(maxe,j+in[i]);

            }
        }
        cerr << 'O' << endl;
	}
	FOR(i,0,N)
	{
	    if (mark[in[i]]>0 && mark[in[i]]<4 )
            ans++;
	}
	cout << ans << endl;
}
