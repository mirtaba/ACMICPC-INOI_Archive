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

const int Maxn = 10000 + 25;
//const int Mod = 1000 * 1000 * 1000 + 7;

pair <LL,PLL> e[Maxn];
LL par[Maxn],size[Maxn],N,M,ans,sum;
LL c1,c2,q1,q2;
vector <LL> weight;
bool d[Maxn];

LL father (int x)
{
    if(par[x] == -1)
        return x;
    return par[x] = father (par[x]);
}

LL merge ( pair <LL,PLL> t)
{
    LL a=t.Y.X;
    LL b=t.Y.Y;
    if (size[a]==0) size[a]=1;
    if (size[b]==0) size[b]=1;
    a =father (a);
    b =father (b);
    if (a==b)
        return 0;
    if (size[a] > size[b] ) swap(a,b);
    par[a]=b;
    size[b] += size[a];
    weight.pb(t.X);
    return t.X;
}

int main()
{
	ios::sync_with_stdio(0);
	MEM(par,0xFF);
	cin >> N >> M;
	if (N == 1 ) {cout << 0 << endl; return 0;}
	FOR(i,0,M)
	{
	    cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;e[i].Y.X--;e[i].Y.Y--;
	}
	sort(e,e+M);
	FOR(i,0,M)
        ans+=merge(e[i]);
    cin >> c1 >> q1 >> c2 >> q2;
    if (c1 > c2)
    {
        swap(c1,c2);
        swap(q1,q2);
    }
    if ( (weight.size() != N-1 )|| (ans>(q1+q2)))
    {
        cout << "Impossible" << endl;
        return 0;
    }
    d[0]=true;
    FOR(i,0,weight.size())
    {
        for (LL j=q1;j>=0;j--)
        {
            if(d[j])
                d[j+weight[i]]=true;
        }
    }
    LL j=q1;
    while(j>0)
    {
        if (d[j] && ((ans-j)<=q2 ) )
            break;
        else
            j--;
    }
    if ( j == 0 && (ans-j)>q2 )
        {cout << "Impossible" << endl; return 0;}
    cout << (LL)((j*c1)+((ans-j)*c2)) << endl;
    return 0;
}

