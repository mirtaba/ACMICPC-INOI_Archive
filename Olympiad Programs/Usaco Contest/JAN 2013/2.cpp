/*
ID: ghoolha1
PROG: paint
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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;

ofstream fout ("paint.out");
ifstream fin ("paint.in");

//#define cin fin
//#define cout fout

LL N,tmp,ans;
vector < pair <LL,bool> > move,movet;
char C;
bool bmp;

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	cin >> tmp >> C;
    if (C == 'R')
    {
        bmp=true;
    }
    else
    {
        bmp=false;
    }
    movet.pb(mp(tmp,bmp));
	FOR(i,1,N)
	{
	    cin >> tmp >> C;
	    if (C == 'R')
	    {
	        bmp=true;
	    }
	    else
	    {
	        bmp=false;
	    }
	    if (bmp == movet.back().Y)
	    {
	        movet.back().X+=tmp;
	    }
	    else
	    {
	        movet.pb(mp(tmp,bmp));
	    }
	}
	N=movet.size();
	for(LL i=N ; i>0 ;i--)
	{
	    move.pb(mp ( MAX( (movet[i].X-movet[i-1].X),0 ),movet[i].Y) );
	}
	move.pb(movet[0]);
	reverse(move.begin(),move.end());
	FOR(i,0,N)
    {
        cerr << move[i].X << ' ' << move[i].Y << endl;
    }
    cerr << "-----------------------" << endl;
	FOR(i,0,N-1)
	{
	    ans+=MIN(move[i].X,move[i+1].X);
        cerr << move[i].X << ' ' << move[i+1].X << " Ans Is: " << ans <<endl;
	    cerr << "-----------------------" << endl;
	}
	cout << ans << endl;

}
