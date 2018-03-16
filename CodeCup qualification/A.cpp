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

const int Maxn = 1000*1000*100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL n,m , tmp , num;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;

    FOR(i,1,m+1)
    {
        if(i%n == 0)
        {
            num = n;
        }
        else
        {
            num = i%n;
        }
        cin >> tmp;
        if(i%3 == 0 || i%7 == 0)
        {
            if(tmp != 0)
            {
                cout << num << endl;
            }
        }
        else
        {
            if(tmp != i)
            {
                cout << num << endl;
            }
        }
    }

}
