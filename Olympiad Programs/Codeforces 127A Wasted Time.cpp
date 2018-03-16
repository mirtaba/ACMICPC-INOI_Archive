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
//#include <iomanip>

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

long double ans=0;
LL tmp,tmp2,N,K,otmp,otmp2;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	cin >> otmp >> otmp2;
	FOR(i,1,N)
	{
	    cin >> tmp >>  tmp2;
	    ans+=sqrt(((tmp-otmp)*(tmp-otmp))+((tmp2-otmp2)*(tmp2-otmp2)));
	    otmp=tmp;
	    otmp2=tmp2;
	}
	cout.precision(12);
	cout << fixed << (long double)((ans*K)/50) << endl;
}
