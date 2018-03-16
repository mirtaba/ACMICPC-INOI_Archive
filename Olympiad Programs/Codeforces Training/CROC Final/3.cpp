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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,K,a[Maxn],k[Maxn],tmp,j,la;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	cin >> a[0];
	la=1;
	FOR(i,1,N)
	{
	    cin >> tmp;
        if (a[la-1]!=tmp)
        {
            a[la]=tmp;
            la++;
        }
        else
        {
            j++;
        }
	}
	N-=j;
	if (a[0]!=a[1])
        k[a[0]]++;
	FOR(i,1,N-1)
	{
	    if (a[i]==a[i-1] && a[i]==a[i+1])
	    {
	        continue;
	    }
	    if (a[i]==a[i-1] && a[i]!=a[i+1])
	    {
	        //cerr << 11 << endl;
            k[a[i]]+=1;
	    }
	    else
	    if (a[i]!=a[i-1] && a[i]==a[i+1])
        {
            //cerr << 22 << endl;
            k[a[i]]+=1;
	    }
	    else
	    {
	        if (a[i-1]==a[i+1])
            {
                //cerr << 33 << endl;
                k[a[i]]+=2;
            }
            else
            {
                //cerr << 44 << endl;
                k[a[i]]+=1;
            }
	    }
	}
	if (a[N-2]!=a[N-1])
        k[a[N-1]]++;
    PLL maxe;
    maxe.X=0;
    maxe.Y=0;
    FOR(i,1,K+1)
    {
        if (maxe.X<k[i])
        {
            maxe.X=k[i];
            maxe.Y=i;
        }
    }
    cout << maxe.Y << endl;
}
