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

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");


vector <LL> G[Maxn],ans;
LL N,M,K,tmp,tmp1,tmp2,S,dis[Maxn];
bool mark[Maxn],markt[Maxn],flag;

LL dfs (LL p)
{
    markt[p]=true;
    FOR (i,0,G[p].size())
    {
        if (G[p][i] == S)
        {
            if (dis[p] > K-2)
            {
                //cerr << p+1 << endl;
                ans.pb(p+1);
                return p;
            }
        }
        if (!markt[G[p][i]] && !mark[G[p][i]])
        {
            markt[G[p][i]]=true;
            dis[G[p][i]]=dis[p]+1;
            if (dfs(G[p][i]) != (-1) )
            {
                //cerr << p+1 << endl;
                ans.pb(p+1);
                return p;
            }
        }
    }
    markt[p]=false;
    dis[p]=-1;
    return -1;
}

int main()
{
	ios::sync_with_stdio(0);
    MEM(dis,0xFF);
	cin >> N >> M >> K;
	FOR (i,0,M)
	{
	    cin >> tmp1 >> tmp2;tmp1--;tmp2--;
	    G[tmp1].pb(tmp2);
	    G[tmp2].pb(tmp1);
	}
	FOR (i,0,N)
	{
	    ans.clear();
	    mark[i]=true;
	    if ( dfs(i) == i )
	    {
	        cout << ans.size() << endl;
	        FOR (j,0,ans.size())
	        {
	            cout << ans[j] << ' ';
	        }
	        break;
	    }
	    MEM(markt,0);
	}
    return 0;
}


