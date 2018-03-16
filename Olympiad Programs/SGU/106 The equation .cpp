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

long double a,b,c,x,y, x1,x2,yy1,yy2;
long i;
LL ans;
int main()
{
	ios::sync_with_stdio(0);
	cin >> a >> b >> c;
	cin >> x1 >> x2;
	cin >> yy1 >> yy2;
	while (x2-x1 >1)
	{
	    i=((x1+x2)/2);
	    y = ((long double)(((a*i) + c)/(-b)));
 	    if ( (y == (long)y) && (yy1 <= y) && (y<=yy2) )
	    {
	        if (b > 0)
                x2=i;
            else
                x1=i;
	    }
	    else
	    {
	        if (b > 0)
                x1=i;
            else
                x2=i;
	    }
	}
	if (b > 0)
	{
	    cout << yy2-x1 << endl;
	}
	else
	{
	    cout << x1 << endl;
	}
    return 0;
}

