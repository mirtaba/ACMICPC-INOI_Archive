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

const int Maxn = 5*100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

/*
ifstream fin("stock.in");
ofstream fout("stock.out");

#define cin fin
#define cout fout
*/

LL M,S,D,m[Maxn],s[100][20];

int main()
{
	ios::sync_with_stdio(0);
	cin >> S >> D >> M;
    FOR(i,0,D)
        FOR(j,0,S)
            cin >> prices[j][i];

    for (int i = 1; i < D; i++)
    {
        for (int j = 0; j <= M; j++)
            mout[j] = j;
        for (int s = 0; s < S; s++)
        {
            int p = prices[i - 1][s];
            int po = prices[i][s];
            for (int k = p; k <= M; k++)
            {
                int trg = mout[k - p] + po;
                if (trg > mout[k]) mout[k] = trg;
            }
        }
        M = mout[M];
    }
    out << M << "\n";
    return 0;
}



