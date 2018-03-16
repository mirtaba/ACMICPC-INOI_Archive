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

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n,m , stmp , ftmp , num , k , GetSize;
bool t[Maxn];

char tmp , mat[Maxn][Maxn];

string SS , s[Maxn] ;
pair < string , string > ans[Maxn];
map <char, int> rowcnt[Maxn], colcnt[Maxn];



int main()
{
	ios::sync_with_stdio(0);
    cin >> n >> m;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            cin >> tmp;
            mat[i][j] = tmp;
            if(rowcnt[i].find(tmp) == rowcnt[i].end())
            {
                rowcnt[i][tmp] = 0;
            }
            if(colcnt[j].find(tmp) == colcnt[j].end())
            {
                colcnt[j][tmp] = 0;
            }
            rowcnt[i][tmp]++;
            colcnt[j][tmp]++;
        }
    }
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            //cerr << rowcnt[i][mat[i][j]] << ' ' <<   colcnt[j][mat[i][j]] << endl;
            if(rowcnt[i][mat[i][j]] == 1 && colcnt[j][mat[i][j]] == 1 )
            {
                cout << mat[i][j];
            }
        }
    }
    cout << endl;

}

