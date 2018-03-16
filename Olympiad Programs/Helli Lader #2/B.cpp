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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

int d[Maxn][Maxn],sum[Maxn][Maxn],egg,flo;
bool flag=true;

int main()
{
	ios::sync_with_stdio(0);

	FOR(i,0,1010)
	{
        FOR(j,0,1010)
        {
            if(i>=10 && j>=10)
                d[i][j] = 1000;
            else
                if(i==0 || j==0)
                    d[i][j] = 0;
            else
                if(j==1)
                    d[i][j] = i;
            else
                if(i<j)
                    d[i][j] = d[i][i];
            else
                d[i][j] = MIN(1000,d[i-1][j-1]+d[i-1][j]+1);
        }
    }
	int j=1;
	FOR (i,1,Maxn-1)
	{
        while (sum[1][j] < i)
        {
            j++;
        }
        d[2][i]=j;
        sum[2][i]=sum[2][i-1]+j;
	}

	while (flag)
	{
	    cin >> egg >> flo ;
	    if (egg== 0 && flo == 0)
	    {
	        flag=false;
	        break;
	    }
	    int lo = 1,hi = flo,mi;

        while(lo<hi)
        {
            mi = (lo+hi)/2;

            if(flo<=d[mi][egg])
                hi = mi;
            else
                lo = mi+1;
        }
        cout << lo << endl;
	}
}
