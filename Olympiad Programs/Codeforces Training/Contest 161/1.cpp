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

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

int m,n,tmp;

int main()
{
	ios::sync_with_stdio(0);
	FOR (i,0,5)
	{
	    FOR(j,0,5)
	    {
	        cin >> tmp;
	        if (tmp == 1)
	        {
	            m=max(2-i,i-2);
	            n=max(2-j,j-2);
	            cout << m+n << endl;
	            break;
	        }
	    }
	    if (tmp==1)
	    {
	        break;
	    }
	}
	return 0;
}
