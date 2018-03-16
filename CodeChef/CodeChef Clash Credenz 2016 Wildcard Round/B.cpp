#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*1000 + 250;
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

        LL n , k , ans = 0;
        cin >> n >> k;
        LL a =0 , b = 0;
        for(int i = n ; i > 0;i--){
            a+=i;
            if((n-i) < k)
                b+=i;
        }
        //cerr << a << ' ' << b << endl;
        ans = a*b;
        cout << ans << endl;
	}
}
