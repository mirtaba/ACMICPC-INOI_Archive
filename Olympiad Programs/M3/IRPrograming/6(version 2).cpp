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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
ifstream fin ("inp");

#define cin fin
//#define cout fout

stack<PII> S;

int table[501][501],dis[501][501];
void BFS(int x ,int y)
{
    S.push(mp(x,y));
    while(!S.empty())
    {
        if ((0<=x||x<=500)||(0<=y||y<=500))
        {

        }

    }
}


int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,501)
	{
	    FOR(j,0,501)
	    {
	        cin >> table[i][j];
	    }
	}

}
