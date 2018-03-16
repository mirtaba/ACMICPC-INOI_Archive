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
#include <iomanip>

#define MAX(a,b) (((a) > (b))? (a) : (b))
#define MIN(a,b) (((a) < (b))? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))
#define FOR(i,a,b) for(long i=a;i<b;i++)
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

//#define cin fin
//#define cout fout

long N;
long tp,tmp1,tmp2;
long sum,siz,pos[Maxn];
vector <long> in;
long double ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	in.pb(0);
	siz=1;
	FOR(i,0,N)
	{
	    cin >> tp;
	    if (tp==3)
	    {
	        siz--;
	        sum-=(in[siz]+pos[siz]);
	        if (siz>0)
                pos[siz-1]+=pos[siz];
	        pos[siz]=0;
	        in.pop_back();

	    }
	    else
	    if (tp==2)
	    {
	        cin >> tmp1;
	        siz++;
	        in.pb(tmp1);
	        sum+=tmp1;
	    }
	    if (tp==1)
	    {
	        cin >> tmp1 >> tmp2;
	        pos[MIN(tmp1-1,siz-1)]+=tmp2;
	        sum+=(tmp1*tmp2);
	    }
	    ans=(double)((double)sum/(double)siz);
	    cout << fixed << setprecision(6) << ans << endl;
	}
}

