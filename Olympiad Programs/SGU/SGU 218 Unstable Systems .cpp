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

const int Maxn = 500 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

int G[Maxn][Maxn];
int match[Maxn],dmatch[Maxn],N,tmp;
int mark[Maxn];

int dfs(int x, int maxe)
{
    mark[x]=1;
    FOR(i,1,N+1)
    {
        if (G[x][i] <= maxe)
        {
            if (dmatch[i]==-1 || (!mark[dmatch[i]] && dfs(dmatch[i],maxe) ) )
            {
                match[x]=i;
                dmatch[i]=x;
                return 1;
            }
        }
    }
    return 0;

}

bool check(int x)
{
    MEM(dmatch,0xFF);
    FOR(i,1,N+1)
    {
        MEM(mark,0);
        if(!dfs(i,x))
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,1,N+1)
	{
	    FOR(j,1,N+1)
	    {
	        cin >> G[i][j];
	    }
	}
	int it1=(-(1e6)-10);
	int it2=(1e6)+10;
	while((it2-it1)>1)
	{
	    tmp=((it1+it2)/2);
	    if (check(tmp))
	    {
	        it2=tmp;
	    }
	    else
	    {
	        it1=tmp;
	    }
	}
    check(it2);
    cout << it2 << endl;
	FOR(i,1,N+1)
	{
        cout << i << ' ' << match[i] << endl;
	}
	return 0;
}
