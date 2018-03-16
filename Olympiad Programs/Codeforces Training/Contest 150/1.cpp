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

const int Maxn = 1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

LL N,K,in[Maxn];
vector <LL> kid[Maxn];
bool mark[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	FOR(i,0,K)
	{
	    cin >> in[i];
	    in[i]--;
	    kid[i].pb(in[i]);
	    mark[in[i]]=true;
	}
	LL u=0;
	FOR(i,0,N*K)
	{
	    if((kid[u].size()>=N) && u<(K-1) )
	    {
	        u++;
	    }
	    if(!mark[i])
            kid[u].pb(i);
	}
	FOR(i,0,K)
	{
	    FOR(j,0,kid[i].size())
	    {
	        cout << kid[i][j]+1 << ' ';
	    }
	    cout << endl;
	}

}
