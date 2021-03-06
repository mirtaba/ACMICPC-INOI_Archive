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

char ans[Maxn];

int main() {
	ios::sync_with_stdio(0);
	int n ;
	cin >> n;
	string s;
	cin >> s;
	if(n%2){
        int t = (n)/2;
        for(int i = 0 ; i < n ; i++){
            int u = t + ((i%2)?((i+1)/2):(-(i/2)));
            ans[u] = s[i];
        }
        for(int i = n-1 ; i >= 0  ; i--){
            cout << ans[i];
        }
        cout << endl;
	}

}
