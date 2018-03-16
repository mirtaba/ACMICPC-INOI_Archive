/*
ID: ghoolha1
PROG: relay
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

ofstream fout ("relay.out");
ifstream fin ("relay.in");

//#define cin fin
//#define cout fout

bool mark[Maxn];
int in[Maxn],N,ans;
vector <int> hod[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	int tmp;
	FOR(i,1,N+1)
	{
	    cin >> tmp;
	    in[i]=tmp;
	    hod[tmp].pb(i);
	}
	cerr << "---------------------------" << endl;
	FOR(t,0,N+1)
	FOR(i,0,N+1)
	{
	    if ( i==0 || mark[i] )
	    {
            FOR(j,0,hod[i].size())
            {
                cerr << i << ' ' << hod[i][j] << endl;
                mark[hod[i][j]]=true;
            }
	    }
	}
	cerr << endl;
	FOR(i,1,N+1)
	{
	    cerr << mark[i] << ' ';
	    if (mark[i])
            ans++;
	}
	cout << endl;
	cout << ans << endl;
}
