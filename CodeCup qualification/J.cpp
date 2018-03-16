/*
ID: One O'Clock
PROG: HOP
LANG: C++
*/

#include <bits/stdc++.h>

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
#define Traxe(X) cerr << #X << " = " << X << endl
#define _ << " _ " <<


using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL n,m , rtmp , ctmp , num , k;
LL r[Maxn] , c[Maxn] , mat[Maxn][Maxn] ;
set < PLL > row , col;
int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	FOR(i,0,k)
	{
	    cin >> rtmp >> ctmp;
	    r[rtmp]++;
	    c[ctmp]++;
	    mat[rtmp][ctmp] = 1;
	}
	FOR(i,1,n+1)
	{
	    row.insert(mp(-r[i],i));
	}
	FOR(i,1,m+1)
	{
	    col.insert(mp(-c[i],i));
	}
    while(k)
    {
        PLL rr = *row.begin();
        PLL cc = *col.begin();
        if(rr.Y > cc.Y)
        {
            FOR(i,1,m+1)
            {
                if(mat[rr.Y][i] == 1)
                {
                    col.erase(mp())
                }
            }
        }
    }

}
