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

const int Maxn = 100*1000 + 25;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 28 ;
//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL gcd(LL a, LL b)
{
    //cerr << a << ' ' << b << endl;
    return (b==0) ? (a) : (gcd(b,a%b));
}


int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	FOR(ttt,0,T)
	{
	    LL a,b,c,d;
        cin >> a >> b >> c >> d;
        LL t = gcd(c,d);
        LL tt = abs(a-b);
        cout << min ( tt%t , t-(tt%t)) << endl;
	}


}
