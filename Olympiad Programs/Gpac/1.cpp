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
#define FOR(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define f1 first
#define f2 second
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 60 + 25;
const int Maxm = 60 + 25;
const int Mod = 1000*1000*100 +25;
const int INFI = 2242545357980376863;

vector <LL> fibos;
LL d[Mod];
LL ans;
unsigned long long ansu;

void cal(LL in)
{
    d[in]=INFI;
    for(int j=fibos.size();j>=0;j--)
    {
        if (in-fibos[j]>0)
            d[in]=min(d[in],d[in-fibos[j]]+1);
    }
}

int main()
{
	ios::sync_with_stdio(0);
	fibos.pb(1);
	fibos.pb(1);
	d[1]=1;
	FOR(i,2,39)
	{
	    fibos.pb(fibos[i-1]+fibos[i-2]);
	    d[fibos[i]]=1;
	}
	cerr << fibos[38] << endl;
	FOR(i,0,1e8)
	{
        if (d[i]==0)    cal(i);
        else
        cerr << i << endl;
        ans+=d[i];
        ansu+=d[i];
    }
    cout << ans << ' ' << ansu << endl;
}
