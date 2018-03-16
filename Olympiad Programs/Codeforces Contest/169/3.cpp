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

const int Maxn = 100*1000*2 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

long N,Q,in[Maxn],cnt[Maxn],ans;
pair <long ,long> q[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> Q;
	FOR(i,0,N)
	{
	    cin >> in[i];
	}
	FOR(i,0,Q)
	{
	    cin >> q[i].X >> q[i].Y;
	    FOR(j,q[i].X-1,q[i].Y)
	    {
	        cnt[j]++;
	    }
	}
	sort(in,in+N);
	sort(cnt,cnt+N);
	FOR(i,0,N)
	{
	    ans+=(cnt[i]*in[i]);
	}
	cout << ans << endl;
	return 0;
}
