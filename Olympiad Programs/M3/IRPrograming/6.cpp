/*
ID: ghoolha1
PROG: greetings
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

const int Maxn = 5*100*100*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("Ans.txt");
ifstream fin ("inp");

#define cin fin
#define cout fout

vector <int> G[Maxn];
bool mark[Maxn];
LL in[501][501],dis[Maxn];
LL table[600][600];
LL mine=4290000000;
LL tmp,d;
deque <PLL> S;

void BFS(LL x)
{
    S.pb(mp(x,0));
    while(!S.empty())
    {
        tmp=S.front().X;
        d=S.front().Y;
        S.pop_front();
        dis[tmp]=MIN(dis[tmp],d);
        if(mark[tmp]==false)
        {
            mark[tmp]=true;
            FOR(i,0,G[tmp].size())
            {
                S.pb(mp(G[tmp][i],d+1));
            }
        }
    }

}


int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,500*500+1)
	{
	    dis[i]=Mod;
	}
	FOR(i,0,501)
	{
	    FOR(j,0,501)
	    {
	        cin >> table[i][j];
	    }
	}
    cerr << "Read done" << endl;
	FOR(i,0,501)
	{
	    FOR(j,0,501)
	    {
	        in[i][j]=(i*501)+j;
	    }
	}
    cerr << "Index done" << endl;
	FOR(i,1,500)
	{
	    FOR(j,1,500)
	    {
	        if (table[i][j]>=table[i][j+1])
            {
                G[in[i][j]].pb(in[i][j+1]);
            }
            if (table[i][j]>=table[i][j-1])
            {
                G[in[i][j]].pb(in[i][j-1]);
            }
            if (table[i][j]>=table[i+1][j])
            {
                G[in[i][j]].pb(in[i+1][j]);
            }
            if (table[i][j]>=table[i-1][j])
            {
                G[in[i][j]].pb(in[i-1][j]);
            }
	    }
	}
	cerr << "Table pulished" << endl;
    BFS(in[250][250]);
    cerr << "BFS done" << endl;
    FOR(i,0,501)
	{
	    FOR(j,0,501)
	    {
	        cout << dis[in[i][j]] << ' ';
	    }
	    cout << endl;
	}
	/**/
    FOR(i,0,501)
    {
        mine=MIN(mine,dis[in[i][0]]);
        mine=MIN(mine,dis[in[i][500]]);
        mine=MIN(mine,dis[in[0][i]]);
        mine=MIN(mine,dis[in[500][i]]);
    }
    cout << mine << endl;
    /**/
}
