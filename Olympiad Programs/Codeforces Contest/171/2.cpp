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

LL N ,t,in[Maxn],dp[Maxn],sum[Maxn],maxe;


int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> t;
	FOR(i,0,N)
	{
	    cin >> in[i];
	}
	//in[N]=100*1000;
	sum[N-1]=in[N-1];
	dp[N-1]=1;
	for (int i=(N-1);i>0;i--)
	{
        if (sum[i]+in[i-1] < t)
        {
            dp[i-1]=dp[i]+1;
            sum[i-1]=sum[i]+in[i-1];
        }
        else
        {

        }
	}
	cout << maxe << endl;
}
