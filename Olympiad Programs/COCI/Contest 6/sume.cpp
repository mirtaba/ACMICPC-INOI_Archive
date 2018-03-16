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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL in[Maxn][Maxn],N,ans[Maxn],tmp1,tmp2,tmp3,mine,sum;

int main()
{
	ios::sync_with_stdio(0);
	mine=1e10;
	cin >> N;
	FOR(i,0,N)
	{
	    FOR(j,0,N)
	    {
	        cin >> in[i][j];
	        ans[i]+=in[i][j];
	    }
	    sum+=ans[i];
	    //mine=MIN(mine,ans[i]);
	}
	if (N==2)
	{
	    cout << ans[0]/2 << ' ' << ans[0]/2 << endl;
	    return 0;
	}
	sum=(sum/(2*(N-1)));
	FOR(i,0,N)
	{
	    ans[i]=((ans[i]-sum)/(N-2));
	    cout << ans[i] << ' ';
	}
	return 0;
}
