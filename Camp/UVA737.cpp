
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

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

bool doesOverlap(PII i , PII j ,PII k)
{
  k.X = max(i.X, j.X);
  k.Y = min(i.Y, j.Y);
  return (k.X < k.Y) ? true : false;
}

int main() {
	ios::sync_with_stdio(0);
	int n;
	while(cin >> n , n) {
        PII x,y,z;
        int tmp;
        cin >> x.X >> y.X >> z.X >> tmp;
        x.Y = x.X + tmp;
        y.Y = y.X + tmp;
        z.Y = z.X + tmp;
        bool flag = true;

        while(n--) {
            PII cx,cy,cz;
            cin >> cx.first >> cy.first >> cz.first >> d;
              if (flag) {
                cx.second = cx.first + d;
                cy.second = cy.first + d;
                cz.second = cz.first + d;
                if (doesOverlap(x, cx, nx) &&
                  doesOverlap(y, cy, ny) && doesOverlap(pz, cz, nz)) {
                  px = nx; py = ny; pz = nz;
                }
                else
                  flag = false;
              }
        }

	}
}
