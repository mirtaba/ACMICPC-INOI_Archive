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

const int Maxn = 5*100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

queue <LL> que;
LL N,M,K,s,t,tmp,tmp1,tmp2,a,e,dis[Maxn];
vector <LL> G[Maxn],vol;
bool mark[Maxn],m[Maxn];

bool BFS (LL q)
{
    FOR(i,0,vol.size())
    {
        que.push(vol[i]);
    }
    que.push(s);
    dis[s]=0;
    mark[s]=true;
    while(que.size())
    {
        int u=que.front();
        for (int i=0;i<G[u].size();i++)
        {
            cerr << u << ' ' << G[u][i] << endl;
            if (!mark[G[u][i]] && (dis[u]+1)<=q)
            {
                que.push(G[u][i]);
                mark[G[u][i]]=true;
                dis[G[u][i]]=(dis[u]+1);
            }
        }
        que.pop();
    }
    tmp=1;
    while(tmp <(N) )
    {
        if(!mark[tmp])
        {
            cerr << ' ' << tmp << endl;
            return false;
        }
        tmp++;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M >> K;
	FOR(i,0,K)
	{
	    cin >> tmp;
	    tmp--;
	    vol.pb(tmp);
	}
	FOR(i,0,M)
	{
	    cin >> tmp1 >> tmp2;tmp1--;tmp2--;
	    G[tmp1].pb(N+i);
	    G[tmp2].pb(N+i);
	    G[N+i].pb(tmp1);
	    G[N+i].pb(tmp2);
	}
	cin >> s >> t;
	a=0;
	e=M;
	cerr << "-------------------" << endl;
	cerr << BFS(3) << endl;
	/*while((e-a) > 1)
	{
	    cerr << a << ' ' << e << endl;
	    MEM(mark,0);
	    if (BFS((a+e)/2)==true)
	    {
	        a=(a+e)/2;
	    }
	    else
	    {
	        e=(a+e)/2;
	    }
	}
	cout << a << endl;*/
}

