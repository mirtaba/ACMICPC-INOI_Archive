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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

long double weight[Maxn][Maxn];
LL e[Maxn];
bool mark[Maxn];
vector <LL> Graph[Maxn];
LL T,N,M,E,S,P,tmp1,tmp2;
long double d[2][Maxn],tmp;

bool Dijestra(LL V,bool who,double speed)
{
    MEM(mark,0);
    set < pair<long double ,LL> > S;
    d[who][V]=0;
    S.insert(make_pair(d[who][V],V));
    while(S.size())
    {
        LL u=S.begin() -> second;
        mark[u]=true;
        S.erase(make_pair(d[who][u],u));
        for (LL i=0;i<Graph[u].size();i++)
        {
            LL x=Graph[u][i];
            if(((d[who][x]>(d[who][u]+(double)(weight[u][x]/speed))) && !mark[x]) && (who==0 || (d[who][u]+(double)(weight[u][x]/speed) < d[2][i] ) ))
            {
                S.erase(make_pair(d[who][x],x));
                d[who][x]=d[who][u]+(double)(weight[u][x]/speed);
                S.insert(make_pair(d[who][x],x));
            }
        }
    }
    FOR(i,0,E)
    {
        if (mark[e[i]])
            return true;
    }
    return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--)
	{
	    cin >> N >> M >> E;
	    FOR(i,0,M)
	    {
	        cin >> tmp1 >> tmp2 >> tmp;
	        tmp=(long double)(tmp/10);
	        tmp1--;
	        tmp2--;
	        Graph[tmp1].pb(tmp2);
	        Graph[tmp2].pb(tmp1);
	        weight[tmp1][tmp2]=tmp;
	        weight[tmp2][tmp1]=tmp;
	    }
	    FOR(i,0,E)
	    {
	        cin >> e[i];
	    }
	    cin >> S >> P;
	    S--,P--;
	    Dijestra(P,0,160);
	    cerr << d[0][1] << endl;
	    long double i=0.00000000001;
	    long double j=1e9;
	    while((j-i)>0.0000001)
	    {
	        if(Dijestra(S,1,(i+j)/2))
	        {
                j=(i+j)/2;
	        }
	        else
	        {
	            i=(i+j)/2;
	        }
	    }
	}
}
