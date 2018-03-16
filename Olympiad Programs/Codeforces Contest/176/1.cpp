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

char ch;
int in[4][4];
int tp;
bool flag;

bool cal(int x,int y)
{
    tp=0;
    tp+=in[x][y];
    tp+=in[x+1][y];
    tp+=in[x][y+1];
    tp+=in[x+1][y+1];
    if (tp>=3 || tp<=1)
    {
        return 1;
    }
    return 0;
}

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,4)
	{
	    FOR(j,0,4)
	    {
	        cin >> ch;
	        if (ch=='#')
	        {
	            in[i][j]=1;
	        }
	    }
	}
	FOR(i,0,3)
	{
	    FOR(j,0,3)
	    {
	        if ( cal(i,j) )
	        {
	            flag=true;
	        }
	    }
	}
	if (flag)
	{
	    cout << "YES" << endl;
	}
	else
	{
	    cout << "NO" << endl;
	}
	return 0;
}
