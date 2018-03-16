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

const int Maxn = 2*100 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

bool mat [Maxn][Maxn];// ماتریس مجاورت گراف
vector < int > G[Maxn];
vector <PII> E;
int N,tmp1,tmp2;
long Ans;
bool mark[Maxn];

PII dfs (int V)
{
    int sze=0,leaf=V;
	mark[V]=true;
	FOR(i,0,G[V].size())
	{
		if( (!mark[G[V][i]]) && (mat[V][G[V][i]]) )
		{
			PII U=dfs(G[V][i]);
			if( (U.Y+1) > sze )
			{
				leaf=U.X;
				sze=U.Y+1;
			}
		}
	}
	return mp(leaf,sze);
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N ;
	FOR(i,0,N-1)
	{
	    cin >> tmp1 >> tmp2;tmp1--;tmp2--;
	    G[tmp1].pb(tmp2);
	    G[tmp2].pb(tmp1);
	    mat[tmp1][tmp2]=true;
	    mat[tmp2][tmp1]=true;
	    E.pb(mp(tmp1,tmp2));
	}
	PII leaf1,path1,leaf2,path2;
	FOR (i,0,E.size())
	{
	    tmp1=E[i].X;
	    tmp2=E[i].Y;
        mat[tmp1][tmp2]=false;
	    mat[tmp2][tmp1]=false;
	    MEM(mark,0);
	    PII leaf1=dfs(tmp1);
	    MEM(mark,0);
	    PII path1=dfs(leaf1.X);
        MEM(mark,0);
	    PII leaf2=dfs(tmp2);
	    MEM(mark,0);
	    PII path2=dfs(leaf2.X);
	    Ans= MAX(Ans,(long)(path1.Y *path2.Y) );
        mat[tmp1][tmp2]=true;
	    mat[tmp2][tmp1]=true;
	}
	cout << Ans << endl;

}

