
#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

inline int ones(int a){
    int res = 0;
    for(int i = 0; i < 32; i++){
        res += (a & 1);
        a = a >> 1;
    }
    return res;
}

int main() {
	ios::sync_with_stdio(0);
	int n ,t,maxx;
	int r[110];
	cin >> t;
	while(t--){
        maxx = -10000;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> r[i];
        }

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                maxx = max(maxx,ones(r[i]^r[j]));
            }
        }
        cout << maxx << endl;
	}
}
