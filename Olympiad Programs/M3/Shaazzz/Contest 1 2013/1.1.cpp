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
const int Mod = 33083;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int d[2][Maxn];
int Ans;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,1,21)
	{
	    d[0][i]+=2;
	    d[0][2*i]++;
	    d[0][3*i]++;
	}
	d[0][25]++;
	d[0][50]++;
	FOR(i,2,121)
	{
        FOR(j,1,i)
        {
            (d[1][i]+=(d[0][j]*d[0][i-j])) %= Mod ;
        }
	}
	FOR(i,2,121)
	{
	    FOR(j,2,i)
	    {
	        int tmp=(d[1][i]*d[1][j]);
	        tmp%=Mod;
	        (Ans+=tmp) %= Mod;
	    }
	}
	cout << Ans << endl;


}
