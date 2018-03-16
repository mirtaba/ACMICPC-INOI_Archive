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

const int Maxn = 60 + 25;
const int Maxm = 60 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL mat[Maxm][Maxn][Maxn],N,M,R,d[Maxm][Maxn],D[Maxn][Maxn][Maxn];

LL floyd(LL color)
{
    FOR(i,0,N)
    {
        FOR(j,0,N)
        {
            d[i][j]=mat[color][i][j];
        }
    }
    FOR(k,1,N)
    {
        FOR(i,0,N)
        {
            FOR(j,0,N)
            {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}


int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> R;
	FOR(i,0,M)
	{
	    FOR(j,0,N)
	    {
	        FOR(t,0,N)
	        {
	            cin >> mat[i][j][t] ;
	        }
	    }
	}
	MEM(D,0x1F);
	FOR(k,0,M)
	{
        floyd(k);
        FOR(i,0,N)
        {
            FOR(j,0,N)
            {
                D[0][i][j]=MIN(D[0][i][j],d[i][j]);
            }
        }
        MEM(d,0);
	}
	FOR(k,1,N)
	{
        FOR(i,0,N)
        {
            FOR(j,0,N)
            {
                D[k][i][j]=D[k-1][i][j];
                FOR(br,0,N)
                {
                    D[k][i][j]=min(D[k][i][j],D[k-1][i][br]+D[0][br][j]);
                }
            }
        }
	}
	LL tmp1,tmp2,tmp;
	FOR(i,0,R)
	{
	    cin >> tmp1 >> tmp2 >> tmp;
	    tmp=MIN(tmp,N-1);
	    cout << D[tmp][tmp1-1][tmp2-1] << endl;
	}
	return 0;
}
