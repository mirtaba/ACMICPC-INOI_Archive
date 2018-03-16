/*
ID: ghoolha1
PROG: cowrace
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

const int Maxn = 1000*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("cowrace.out");
ifstream fin ("cowrace.in");

#define cin fin
#define cout fout

long t[2][Maxn],N,M,tmp1,tmp2,sum,ans,last=1;
bool flag;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> M;
	FOR(i,1,N+1)
	{
	    cin >> tmp1 >> tmp2;
	    FOR(j,last,last+tmp2)
	    {
	        t[0][j]=t[0][j-1]+tmp1;
	    }
	    last+=tmp2;
	}
	last=1;
    FOR(i,1,M+1)
	{
	    cin >> tmp1 >> tmp2;
	    sum+=tmp2;
	    FOR(j,last,last+1+tmp2)
	    {
	        t[1][j]=t[1][j-1]+tmp1;
	    }
        last+=tmp2;
	}
	FOR(i,1,sum+1)
	{
	    if (t[0][i] > t[1][i])
	    {
	        if (!flag)
	        {
	            ans++;
	        }
	        flag=true;
	    }
	    else
	    {
	        if (flag)
	        {
	            ans++;
	        }
	        flag=false;
	    }
	}
	cout << ans << endl;
}
