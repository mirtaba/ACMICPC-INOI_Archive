#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 40*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
        long double n , k;
        cin >> n >> k;
        long double tmp = n;
        int A[Maxn], B[Maxn];
        for(int i = 0; i < k ; i++){

            cin >> A[i];

        }
        for(int i = 0; i < k ; i++){

            cin >> B[i];

        }
        for(int i = 0; i < k ; i++){

            long double tp = (long double)(tmp * A[i]) / B[i];
            tmp +=tp;

        }
        long double face = tmp - n;

        long double ans = (double)face / tmp;

        cout << (LL)(ans * 100) << endl;



	}
}
