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

LL in[Maxn],N,K,tmp,lacol;
set <PLL> S;
LL col[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	FOR(i,0,N)
	{
	    cin >> in[i];
	}
	sort (in,in+N);
	lacol=1;
	FOR (i,0,N)
	{
	    tmp = S.begin() -> X;
	    if (tmp == in[i])
	    {
	        col[i]= S.begin() -> Y;
	        S.erase(S.begin());
	    }
	    else
	    {
	        col[i]=lacol;
	        lacol++;
	        S.insert(mp(in[i]*K,lacol-1));
	    }
	}
	cout << lacol-1 << endl;

}
