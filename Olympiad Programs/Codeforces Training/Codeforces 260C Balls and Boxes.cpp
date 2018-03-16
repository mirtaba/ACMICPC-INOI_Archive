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

LL N,x,in[Maxn],ans[Maxn],A;
PLL mine;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> x;
	x--;
	cin >> in[0];
	mine.X=in[0];
	FOR(i,1,N)
	{
	    cin >> in[i];
	    LL dismin=(x>mine.Y) ? x-mine.Y : mine.Y-x;
	    LL disi=(x>i) ? x-i : i-x;
	    if(mine.X > in[i] || ((mine.X==in[i]) && (disi<=dismin)) )
	    {
	        mine.X=in[i];
	        mine.Y=i;
	    }
	}
	if (x >= mine.Y)
	{
	    FOR(i,0,N)
	    {
	        ans[i]=(in[i]-mine.X);
	        if (i<=x && i>mine.Y)
	        {
	            ans[i]--;
	        }
	    }
	    ans[mine.Y]=(mine.X*N)+(x-mine.Y);
	}
	else
	{
	    FOR(i,0,N)
	    {
	        ans[i]=(in[i]-mine.X);
	        if (i<=x || i>mine.Y)
	        {
	            ans[i]--;
	            if (ans[i]<0)
	            {
	                ans[i]++;
	                A++;
	            }
	        }
	    }
	    ans[mine.Y]=(mine.X*N)+(N-(mine.Y-x))-A;
	}
	FOR(i,0,N)
	{
	    cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}
