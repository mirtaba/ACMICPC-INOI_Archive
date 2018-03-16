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
//const int Mod = 1000 * 1000 * 1000 + 7;

long in[Maxn],n,s,t,dis[Maxn],i,j;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	FOR(d,0,n)
	{
	    cin >> in[d];
	    dis[d]=(10000);
	}
	cin >> s >> t;
	s--;
	t--;
	dis[s]=0;
	i=s;
	j=0;
	while(j<=n)
	{
	    i++;
	    j++;
        dis[i%n]=MIN(dis[(i-1)%n]+in[(i-1)%n],dis[i%n]);
	}
	i=s;
	j=0;
	while(j<=n)
	{
	    i--;
	    if (i<0)
	    {
	        i=n-1;
	    }
	    j++;
        dis[i%n]=MIN(dis[(i+1)%n]+in[i%n],dis[i%n]);
	}
    cout << dis[t] << endl;
}
