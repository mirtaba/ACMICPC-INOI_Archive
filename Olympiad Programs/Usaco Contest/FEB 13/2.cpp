/*
ID: ghoolha1
PROG: crossings
LANG: C++
*/
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
#include <fstream>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(long i=a;i<b;i++)
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

ofstream fout ("crossings.out");
ifstream fin ("crossings.in");

#define cin fin
#define cout fout

long N,s[Maxn],ans;
pair <long,long> in[Maxn];

long pl,ph,g,j;
long find(long i)
{
    g=in[i].Y;
    if (s[i]==g)
    {
        return i;
    }
    if (s[i] > g)
    {
        pl=0;
        ph=i;
    }
    else
    {
        pl=i;
        ph=N;
    }
    while( (ph-pl)>1 )
    {
        j=(ph+pl)/2;
        if (s[j]>g)
        {
            ph=j;
        }
        else
        {
            pl=j;
        }
    }
    if (s[pl]==g)
    {
        return pl;
    }
    if (s[ph]==g)
    {
        return ph;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR (i,0,N)
	{
	    cin >> in[i].X >> in[i].Y;
	    s[i]=in[i].Y;
	}
	sort(s,s+N);
	sort(in,in+N);
	long tmp,maxe=(-1);
	FOR(i,0,N)
	{
	    tmp=find(i);
	    if (tmp>i)
	    {
	        maxe=MAX(maxe,tmp);
	    }
        if (i <= maxe)
        {
            ans++;
        }
	}
	cout << (long)(N-ans) << endl;

}

