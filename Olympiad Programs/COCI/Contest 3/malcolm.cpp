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

const int Maxn = 3*100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

string tmp;
short N,K,d[Maxn][30],in[Maxn],k,ans,maxe;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	cin >> tmp;
	in[0]=tmp.size();
	d[0][tmp.size()]=1;
	maxe=tmp.size();
	FOR(i,1,N)
	{
	    FOR(j,0,maxe+1)
	    {
	        d[i][j]=d[i-1][j];
	    }
	    cin >> tmp;
	    in[i]=tmp.size();
	    d[i][tmp.size()]=d[i-1][tmp.size()]+1;
	}
	/*
	FOR(i,0,N)
        FOR(j,0,maxe+1)
	    {
	        cerr << i << ' ' << j << ' ' << d[i][j] << endl;
	    }
	    */
	FOR(i,0,N)
	{
	    if ((K+i)>=N)
            k=(N-1);
        else
            k=K+i;
	    ans+=(d[k][in[i]]-d[i][in[i]]);
	}
	cout << ans << endl;
}
