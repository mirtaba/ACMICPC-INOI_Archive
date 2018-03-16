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
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


int table[20][8][8];
void clr(int t)
{
    FOR(i,0,8)
    {
        table[t][i][0]=0;
        table[t][i][8]=0;
        table[t][0][i]=0;
        table[t][8][i]=0;
    }
}


int main()
{
	ios::sync_with_stdio(0);
	table[1][3][4]=1;
	table[1][4][3]=1;
	table[1][5][4]=1;
	table[1][4][5]=1;
	FOR(l,2,17)
	{
	    clr(l-1);
        FOR(i,1,8)
        {
            FOR(j,1,8)
            {
                table[l][i][j]+=table[l-1][i-1][j];
                table[l][i][j]+=table[l-1][i+1][j];
                table[l][i][j]+=table[l-1][i][j-1];
                table[l][i][j]+=table[l-1][i][j+1];
            }
        }
	}
	cout << table[16][4][4] << endl;
}
