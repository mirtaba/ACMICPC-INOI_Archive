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
#define PI 3.14159265

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,b[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
    if (N<3)
    {
        cout << -1 << endl;
        return 0;
    }
    if (N==3)
    {
        cout << 210 << endl;
        return 0;
    }
    b[0]=50;
    FOR(i,1,N-2)
    {
        b[i]=((10*b[i-1])%210);
    }
    cout << 1;
    FOR(i,0,N-4)
    {
        cout << 0;
    }
    if (b[N-4] > 99)
    {
        cout << b[N-4] << endl;
    }
    else
    {
        cout << 0;
        cout << b[N-4] << endl;
    }
}

