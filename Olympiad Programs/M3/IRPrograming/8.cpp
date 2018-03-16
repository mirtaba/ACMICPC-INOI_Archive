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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
ifstream fin ("8.in");

#define cin fin
//#define cout fout

LL M,N;


set < PLL > S;
vector <LL> G[Maxn];
bool mark[Maxn];
LL d[Maxn],w[Maxn][Maxn];
PLL u;
LL x,tp1,tp2,tmp;
void Dij()
{
    S.insert(mp(1000*1000*1000,0));
    while(!S.empty())
    {
        u=*S.begin();
        S.erase(mp(u.X,u.Y));
        u.X=-u.X;
        mark[u.Y]=true;
        FOR(i,0,G[u.Y].size() )
        {
            x=G[u.Y][i];
            if(d[x]<min(d[u.Y],w[u.Y][x]) && !mark[x])
            {
                S.erase(mp(-d[x],x));
                d[x]=min(d[u.Y],w[u.Y][x]);
                S.insert(mp(-d[x],x));
            }

        }

    }
}


int main()
{
	ios::sync_with_stdio(0);
	d[0]=1000*1000*1000;
	FOR(i,0,1000*100)
	{
	    cin >> tp1 >> tp2 >> tmp;tp1--;tp2--;
	    w[tp1][tp2]=tmp;
	    w[tp2][tp1]=tmp;
	    G[tp1].pb(tp2);
	    G[tp2].pb(tp1);
	}
	Dij();
	cout << d[999] << endl;
}

