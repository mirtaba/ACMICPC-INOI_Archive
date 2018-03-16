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


vector <LL> G[Maxn];
LL d[Maxn][Maxn],N,M,K,tmp,tmp1,tmp2;

int main()
{
    MEM(d,0xEF);
    cerr << d[4][2] << endl;
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	FOR (i,0,M)
	{
	    cin >> tmp1 >> tmp2;tmp1--;tmp2--;
	    G[tmp1].pb(tmp2);
	    G[tmp2].pb(tmp1);
	    d[tmp1][tmp2]=1;
	    d[tmp2][tmp1]=1;
	}
    FOR(i,0,N)
    {
        FOR(j,0,N)
        {
            FOR(t,0,N)
            {
                d[i][j]=MIN(d[i][j],d[i][t]+d[t][j]);
            }
        }
    }
}
