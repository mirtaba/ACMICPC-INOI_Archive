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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,in[Maxn],maxe,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	if (N<3 || N%2 == 0)
	{
	    cout << -1 << endl;
	    return 0;
	}
	FOR(i,1,N+1)
	{
	    cin >> in[i];
	}
	for (LL i=N;i >0 ; i-=2 )
	{
	    maxe=max(in[i],in[i-1]);
	    in[i]=0; in[i-1]=0;
	    in[i/2]-=min(in[i/2],maxe);
	    ans+=maxe;
	}
	cout << ans << endl;
}

