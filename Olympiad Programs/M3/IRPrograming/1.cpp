
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

const int Maxn = 100+ 25;
const int Mod = 13921392;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int d[Maxn][Maxn];


int main()
{
	ios::sync_with_stdio(0);
	d[1][1]=1;
	FOR(i,1,101)
	{
	    FOR(j,1,101)
	    {
	        if ( ((i+j)%5)==2)
            {
                if(i>2)
                    (d[i][j]+=d[i-2][j]) %= Mod ;
                if(j>2)
                    (d[i][j]+=d[i][j-2]) %= Mod ;
                (d[i][j]+=d[i-1][j-1]) %= Mod ;
            }
            else
            {
                (d[i][j]+=d[i-1][j]) %= Mod ;
                (d[i][j]+=d[i][j-1]) %= Mod ;
            }
	    }
	}
	FOR(i,1,11)
	{
	    FOR(j,1,11)
	    {
	        cerr << d[i][j] << ' ';
	    }
	    cerr << endl;
	}
	cout << d[100][100] << endl;
}
