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

const int Maxn = 100*3+ 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int INF = 2147483647 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

struct junction
{
    bool C;
    int in0,in1;
    int rem;
} cros[Maxn];

vector <PII> G[Maxn];
int S,E,N,M,dist,u,colu,intu,disu;
long d[Maxn];
set <PII> dis;
bool mark[Maxn];
int from[Maxn];
vector <int> ans;

pair <bool,long> Up(int V, int time) // return's the color of V in time "time"
{
    int intr0=cros[V].in0;
    int intr1=cros[V].in1;

    if (time<cros[V].rem )
    {
        return mp(cros[V].C ,cros[V].rem-time );
    }
    time-=cros[V].rem;
    time= time%(intr0+intr1);
    if ( cros[V].C == 0)
    {
        if (time<intr1)
        {
            return mp(1,intr1-time);
        }
        else
        {
            return mp(0,intr1+intr0-time );
        }
    }
    else
    {
        if (time<cros[V].in0)
        {
            return mp(0,intr0-time);
        }
        else
        {
            return mp(1,intr1+intr0-time);
        }
    }
}

int Dijkstra ()
{
    if (!dis.size())
    {
        return 0;
    }
    int v=dis.begin() -> Y;
    int time=dis.begin() -> X;
    bool col=(Up(v,d[v]).X);
    int ttoch(Up(v,d[v]).Y);
    mark[v]=1;
    dis.erase(dis.begin());
    FOR( i,0,G[v].size() )
    {
        u= G[v][i].X;
        disu=G[v][i].Y;
        colu=Up(u,time).X;
        intu=Up(u,time).Y;
        if (!mark[u])
        {
            if ( col == colu )
            {
                dist=d[v]+disu;
            }
            else
            {
                if (intu != ttoch)
                {
                    dist=d[v]+disu+MIN(intu,ttoch);
                }
                else
                {
                    if (Up(v,time+intu).Y == Up(u,time+ttoch).Y )
                    {
                        dist=INF;
                    }
                    else
                    {
                        dist=d[v]+disu+MIN(Up(v,time+intu).Y , Up(u,time+ttoch).Y)+ttoch;
                    }
                }
            }
            if (dist < d[u])
            {
                dis.erase(mp(d[u],u));
                d[u]=dist;
                from[u]=v;
                dis.insert(mp(d[u],u));
            }
        }
        //system("pause");
    }
    Dijkstra();
}

char tmp;
int tmp1,tmp2,tmp3;

int main()
{
	ios::sync_with_stdio(0);
	cin >> S >> E >> N >> M;S--;E--;
	FOR (i,0,N)
	{
	    cin >> tmp >> cros[i].rem >> cros[i].in0 >> cros[i].in1;
	    if (tmp=='B')
	    {
	        cros[i].C=0;
	    }
	    else
	    {
	        cros[i].C=1;
	    }
	}
	FOR(i,0,M)
	{
	    cin >> tmp1 >> tmp2 >> tmp3; tmp1--;tmp2--;
	    G[tmp1].pb(mp(tmp2,tmp3));
	    G[tmp2].pb(mp(tmp1,tmp3));
	}
	FOR(i,0,N+10)
	{
	    d[i]=INF;
	}
	d[S]=0;
    dis.insert(mp(d[S],S));
	Dijkstra();
	if (d[E]<INF)
	{
        cout << d[E] << endl;
        tmp1=E;
        ans.pb(E+1);
        while(tmp1 != S)
        {
            tmp2=from[tmp1];
            ans.pb(tmp2+1);
            tmp1=tmp2;
        }
        reverse(ans.begin(),ans.end());
        FOR(i,0,ans.size())
        {
            cout << ans[i];
            if (i != ans.size()-1)
                cout << ' ';
        }
        cout << endl;
        return 0;
	}
	else
	{
	    cout << 0 << endl;
	}
}
