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

const int Maxn = 1000*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,M,tmp,tmp1,tmp2,u;
vector <int> in[Maxn],out[Maxn];
int tag[Maxn];
bool Mark[Maxn],mark[Maxn];

void dfsv1(int v)
{
    Mark[v]=true;
    FOR(i,0,out[v].size())
    {
        u=out[v][i];
        if (!Mark[u] && tag[u]!=1)
        {
            dfsv1(u);
        }
    }
}

void dfsv2(int v)
{
    FOR(i,0,in[v].size())
    {
        u=in[v][i];
        if (!mark[u])
        {
            mark[u]=true;
            if (tag[u]!=1)
                dfsv2(u);
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	FOR(i,0,N)
	{
	    cin >> tmp;
	    tag[i]=tmp;
	}
	FOR(i,0,M)
	{
	    cin >> tmp1 >> tmp2;
        out[tmp1-1].pb(tmp2-1);
        in[tmp2-1].pb(tmp1-1);
    }
    // if we can find a path from a condition 1 to a vertex V and a path with reversed edges ,then we can say the V is good;
    FOR(i,0,N)
    {
        if (tag[i]==1)
            dfsv1(i);
        else
        if (tag[i]==2)
        {
            mark[i]=true;
            dfsv2(i);
        }

    }
    FOR(i,0,N)
    {
        cout << (Mark[i] && mark[i]) << endl;
    }



}
