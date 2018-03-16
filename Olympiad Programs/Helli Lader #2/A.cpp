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

long N,M,D,L,s[Maxn],Ans,t;
long line[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> D >> L;
	FOR (i,0,N)
	{
	    cin >> s[i];
	}
	sort(s,s+N);
    FOR(i,0,N)
    {
        if (s[i]-(D*(line[t])) >= L)
        {
            line[t]++;
            t++;
            t=(t%M);
            Ans++;
        }
    }
    cout << Ans << endl;
}
