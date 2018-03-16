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
    int n,b,d , waste = 0 , ans = 0;
	cin >> n >> b >> d;
	for(int i = 0; i < n ; i++){
        int tp;
        cin >> tp;
        if(tp > b) continue;
        waste += tp;
        if(waste > d) { ans++; waste = 0;}
	}
	cout << ans << endl;

}
