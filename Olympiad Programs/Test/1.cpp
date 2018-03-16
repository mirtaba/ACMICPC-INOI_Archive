/*
ID: ghoolha1
PROG: greetings
LANG: C++
*/
#include <iostream.h>
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

//using namespace std;
/**/
typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;
/**/
const int Maxn = 10*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int S1[Maxn],S2[Maxn];
int d[Maxn][Maxn];
vector <int> ans;

int main()
{
	ios::sync_with_stdio(0);
	FOR(i,0,7)
        cin >> S1[i];
	FOR(i,0,6)
        cin >> S2[i];
	cerr <<"HaHa";
	FOR(i,0,7)
	{
	    FOR(j,0,6)
	    {
	        if (S1[i]==S2[j])
	        {
	            ans.pb(S1[i]);
	            d[i][j]=d[i-1][j-1]+1;
	        }
	        else
	        if (d[i-1][j]>=d[i][j-1])
	        {
	            d[i][j]=d[i-1][j];
	        }
	        else
	        {
	            d[i][j]=d[i][j-1];
	        }
	    }
	}
	cout << d[6][5] << endl;
	FOR(i,0,ans.size())
	{
	    cout << ans[i];
	}
	cout << endl;
	return 0;
}
