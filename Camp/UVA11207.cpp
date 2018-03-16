
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

//ofstream fout ("11207.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {


	ios::sync_with_stdio(0);

    LL n;
	while(cin >> n , n) {

        double maxEdge = -1;
        LL ansIndex = -1;

        LL tp1,tp2;
        for(int i = 0 ; i < n ; i++) {

            cin >> tp1 >> tp2;
            if(tp1 > tp2) swap(tp1,tp2);
            double tmpMaxEdge = ( (double)tp1/ 2.0);
            tmpMaxEdge = MAX(tmpMaxEdge ,  MIN( (double)tp2/4 , tp1) );
            if(tmpMaxEdge > maxEdge ) {
                //cerr << tmpMaxEdge << endl;
                maxEdge = tmpMaxEdge;
                ansIndex = i+1;
            }
        }
        cout << ansIndex << endl;
	}





}
