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
#include <iomanip>

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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

long double Min,NPC,mar[Maxn],tmp1,tmp2,tmp;
LL N;

int main()
{
	ios::sync_with_stdio(0);
	cin >> tmp1 >> tmp2;
	NPC=(tmp1/tmp2);
	cin >> N;
	Min=NPC;
	FOR(i,0,N)
	{
	    cin >> tmp1 >> tmp2;
	    mar[i]=(tmp1/tmp2);
	    Min = min(mar[i],Min);
	}
	cout << fixed << setprecision (2) << Min*1000 << endl;
}
