/*
ID: One O'Clock
PROG: Famil Dor
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

LL n,m , stmp , ftmp , num , k;
bool t[Maxn];

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	FOR(i,0,n)
	{
	    t[i] = 1;
	}
    FOR(i,0,m)
    {
        cin >> stmp >> ftmp;
        FOR(j,stmp,ftmp+1)
        {
            t[j] = 0;
        }
    }
    cin >> k;
    FOR(i,0,k)
    {
        cin >> stmp >> ftmp;
        FOR(j,stmp,ftmp+1)
        {
            t[j] = 1;
        }
    }
    FOR(i,0,n)
    {
        if(t[i])
            cout << i << ' ';
    }
    cout << endl;

}
