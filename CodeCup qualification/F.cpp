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

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n,m , stmp , ftmp , num , k , GetSize;
bool t[Maxn];

string SS , s ;
pair < string , string > ans[Maxn];
map <char, char> pol;


int main()
{
	ios::sync_with_stdio(0);

    cin >> SS;
    FOR(i,0,26)
    {
        pol[SS[i]] = 'a' + i;
    }

    cin >> n;

    FOR(i,0,n)
    {
        cin >> s;
        string t =s;
        FOR(j,0,t.size())
        {
            t[j] = pol[t[j]];
        }
        ans[i].X=t;
        ans[i].Y=s;
    }
    sort(ans,ans+n);
    reverse(ans,ans+n);
    FOR(i,0,n)
    {
        cout << ans[i].Y << endl;
    }

}

