/*
ID: ghoolha1
PROG: assign
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

const int Maxn = 25;
const int Mod = 1000 * 1000 * 1000 + 7;


ofstream fout ("assign.out");
ifstream fin ("assign.in");

#define cin fin
#define cout fout


LL ans;
short col[Maxn],N,K,tmp1,tmp2;
vector <int> s[Maxn],d[Maxn];
char tp;

bool trak(short i,short c)
{
    //cerr << i << ' ' << c << ' ';
    col[i]=c;
    FOR(j,0,s[i].size())
    {
        if (col[s[i][j]]!=0 && col[s[i][j]]!=c)
        {
            col[i]=0;
            //cerr << 0 << endl;
            return 0;
        }
    }
    FOR(j,0,d[i].size())
    {
        if (col[d[i][j]]!=0 && col[d[i][j]]==c)
        {
            col[i]=0;
            //cerr << 0 << endl;
            return 0;
        }
    }
    if (i<(N-1))
    {
        FOR(j,i+1,N)
        {
            col[j]=0;
        }
        trak(i+1,1);
        FOR(j,i+1,N)
        {
            col[j]=0;
        }
        trak(i+1,2);
        FOR(j,i+1,N)
        {
            col[j]=0;
        }
        trak(i+1,3);
        return 1;
    }
    else
    {
        /*
        FOR(i,0,N)
        {
            cerr << col[i] << ' ';
        }
        cerr << "Ans++" << endl;
        */
        ans++;
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> N >> K;
	FOR(i,0,K)
	{
	    cin >> tp >> tmp1 >> tmp2;tmp1--;tmp2--;
	    if (tp=='S')
	    {
	        s[tmp1].pb(tmp2);
	        s[tmp2].pb(tmp1);
	    }
	    else
	    {
	        d[tmp1].pb(tmp2);
	        d[tmp2].pb(tmp1);
	    }
	}
	trak(0,1);
	FOR(i,0,N)
	{
	    col[i]=0;
	}
	trak(0,2);
	FOR(i,0,N)
	{
	    col[i]=0;
	}
	trak(0,3);
	cout << ans << endl;
}
