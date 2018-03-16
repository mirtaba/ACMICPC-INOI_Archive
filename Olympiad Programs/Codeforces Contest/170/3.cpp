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

const int Maxn = 100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

vector <int> lan[Maxn],ver[Maxn];
int N,M,ans,tp,tmp1,tmp2,colo;
int markver[Maxn],marklan[Maxn];

int dfslan(int S,int color);
int dfs(int S,int color)
{
    markver[S]=color;
    FOR(i,0,ver[S].size())
    {
        if (marklan[ver[S][i]]==0)
            dfslan(ver[S][i],color);
        else
        if (marklan[ver[S][i]]!=color)
        {
            cerr << "vayyyyyyyyyyy" << endl;
        }
    }
    return 0;
}
int dfslan(int S,int color)
{
    marklan[S]=color;
    FOR(i,0,lan[S].size())
    {
        if (markver[lan[S][i]]==0)
            dfs(lan[S][i],color);
        else
        if (markver[lan[S][i]]!=color)
        {
            cerr << "vayyyyyyyyyyy" << endl;
        }
    }
    return 0;

}



int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	FOR(i,0,N)
	{
	    cin >> tp;
            FOR(j,0,tp)
            {
                cin >> tmp1;
                ver[i].pb(tmp1);
                lan[tmp1].pb(i);
            }
	}
	bool flag=0;
	FOR(i,0,M)
	{
	    if (marklan[i]==0 && lan[i].size()>0)
	    {
	        flag=1;
	        colo++;
	        dfslan(i,colo);
	    }
	}
	if (flag)
        colo--;
	ans+=colo;
	FOR(i,0,N)
	{
	    if (markver[i]==0)
            ans++;
	}
	cout << ans << endl;
}
