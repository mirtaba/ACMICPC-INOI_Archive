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

const int Maxn = 10000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL n,k;
bool mark[Maxn];
char tp='b',S[Maxn];
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	if (k>n)
    {
        cout << -1 << endl;
        return 0;
    }
    if (k==1)
    {
        if (n==1)
        {
            cout << 'a' << endl;
            return 0;
        }
        else
        {
            cout << -1 << endl;
            return 0;
        }
    }
	FOR(i,0,n-k+2)
	{
	    if (i%2==0)
        {
            S[i]='a';
        }
        else
        {
            S[i]='b';
        }
	}
	FOR(i,n-k+2,n)
	{
	    tp++;
	    S[i]=tp;
	}
	cout << S << endl;
}
