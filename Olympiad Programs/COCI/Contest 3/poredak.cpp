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

const int Maxn = 25*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

string tmp;
map <string,short> m;
short N,in[Maxn];
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,N)
	{
	    cin >> tmp;
	    m[tmp]=i;
	}
	FOR(i,0,N)
	{
	    cin >> tmp;
	    in[i]=m[tmp];
	    FOR(j,0,i)
	    {
	        if (in[j] < in[i])
                ans++;
	    }
	}
	cout << ans << '/' << (LL)((N*(N-1))/2) << endl;
}

