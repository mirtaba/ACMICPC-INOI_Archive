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
typedef unsigned long long ULL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;

const int Maxn = 500*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const LL INFI = 9223372036854775807;

LL N,in[2][Maxn],a,b;
ULL ans;
PLL min1A,min2A,min1B,min2B;
set <PLL> S;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	min1A.X=INFI;
	min1B.X=INFI;
	FOR(i,0,N)
	{
	    cin >> in[0][i] >> in[1][i];
	    if (min1A.X >= in[0][i])
	    {
	        min2A.X=min1A.X;
	        min2A.Y=min1A.Y;
	        min1A.X=in[0][i];
	        min1A.Y=i;
	    }
        if (min1B.X >= in[1][i])
	    {
	        min2B.X=min1B.X;
	        min2B.Y=min1B.Y;
	        min1B.X=in[1][i];
	        min1B.Y=i;
	    }
	}
	cout << min1A.X << endl;
	if (min2A.X == 0)
	{
        min2A.X = min1A.X;
	}
    if (min2B.X == 0)
    {
        min2B.X = min1B.X;
    }
    if (min1A.Y != min1B.Y)
	{
	    cout << (LL)(min1A.X+min1B.X) << endl;
	    a=min1A.Y;
	    b=min1B.Y;
	    ans=min1A.X+min1B.X;
	}
	else
	{
	    if ( (min1A.X+min2B.X) < (min2A.X+min1B.X) )
	    {
            cout << (LL)(min1A.X+min2B.X) << endl;
            a=min1A.Y;
            b=min2B.Y;
            ans=min1A.X+min2B.X;
	    }
	    else
	    {
	        cout << (LL)(min2A.X+min1B.X) << endl;
            a=min2A.Y;
            b=min1B.Y;
	        ans=min2A.X+min1B.X;
	    }
	}
	FOR(i,0,N)
	{
	    if (i != a && i != b)
	    {
	        S.insert(mp(in[1][i],i));
	    }
	}
    FOR(i,0,N-2)
	{
        ans+=S.begin() -> X;
        S.erase(mp(S.begin() -> X , S.begin() -> Y));
        cout << ans << endl;
	}


}
