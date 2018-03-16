
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
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("460.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;


	while(n--)
    {
        PII p1 , p2 , p3,p4;
        cin >> p1.X >> p1.Y >> p2.X >> p2.Y;
        cin >> p3.X >> p3.Y >> p4.X >> p4.Y;
        bool noOverlapFlag = 0;

        if(p2.X <= p3.X || p1.X >= p4.X) {
            noOverlapFlag = 1;
        }

        if(p2.Y <= p3.Y || p1.Y >= p4.Y) {
            noOverlapFlag = 1;
        }

        if(noOverlapFlag) {
            cout << "No Overlap" << endl;
        }
        else {
            cout << max(p1.X,p3.X) << ' ' << max(p1.Y,p3.Y) << ' '<< min(p2.X,p4.X) << ' '<< min(p2.Y,p4.Y) << endl;
        }
        if(n)
            cout << endl;

    }

}
