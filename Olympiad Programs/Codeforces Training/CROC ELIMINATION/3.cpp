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

LL in[Maxn],N,ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,1,N+1)
	{
	    cin >>in[i];
	}
	if (N<3)
	{
	    cout << -1;
	}
	else
	{
        FOR(i,1,N+1)
        {
            ans+=in[i];
            in[2*i]-=min(in[2*i],in[i]);
            in[(2*i)+1]-=min(in[(2*i)+1],in[i]);
            in[i]=0;
        }
        cout << ans << endl;
	}
}

