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

LL N,in[2],t[2],tmp,tmp2,tmp1;


int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	FOR(i,0,N)
	{
	    cin >> tmp;
	    cin >> tmp1 >> tmp2;
	    t[tmp-1]+=tmp2;
	    in[tmp-1]+=tmp1;
	}
	if (in[0] >= t[0])
	{
	    cout << "LIVE" << endl;
	}
	else
	{
	    cout << "DEAD" << endl;
	}
	if (in[1] >= t[1])
	{
	    cout << "LIVE" << endl;
	}
	else
	{
	    cout << "DEAD" << endl;
	}
}
