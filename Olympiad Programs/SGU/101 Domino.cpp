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

int N,mark[Maxn][Maxn],G[Maxn][Maxn],tmp1,tmp2,D[Maxn];
bool Mark[Maxn][Maxn];
vector <int> domino[Maxn][Maxn],ans;
PII odd;
int x1,x2;
int euler (int V)
{
    FOR(i,0,7)
    {
        if (mark[V][i]<G[V][i])
        {
            mark[V][i]++;
            mark[i][V]++;
            euler(i);
        }
    }
    ans.pb(V);
    return 0;

}



int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR (i,0,N)
	{
	    cin >> tmp1 >> tmp2;
	    G[tmp1][tmp2]++;
	    G[tmp2][tmp1]++;
        domino[tmp1][tmp2].pb(i);
        D[tmp1]++;
        D[tmp2]++;
	}
	odd.Y = -1 ;
	FOR(i,0,7)
	{
	    if (odd.Y==-1 && D[i]>0)
            odd.Y=i;
	    if (D[i]%2)
            odd.X++,odd.Y=i;
	}
	if (odd.X>2)
	{
	    cout << "No solution" << endl;
	    return 0;
	}
    euler(odd.Y);
    if (ans.size()!= (N+1))
    {
        cout << "No solution" << endl;
        return 0;
    }
    FOR(i,0,N)
    {
        x1=ans[i];
        x2=ans[i+1];
        if (domino[x1][x2].size()>0)
        {
            cout << domino[x1][x2][0]+1 << " +" << endl;
            domino[x1][x2].erase(domino[x1][x2].begin());
        }
        else
        {
            cout << domino[x2][x1][0]+1 << " -" << endl;
            domino[x2][x1].erase(domino[x2][x1].begin());
        }
    }
    return 0;

}

