#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n , t , tmp;

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> t;
	bool flag = false;
	for(int i = 0 ; i < n ; i++){
        cin >> tmp;
        if(!flag){
            tmp = 86400-tmp;
            t = t - tmp;
            if(t <= 0){
                cout << i+1 << endl;
                flag = true;
            }
        }
	}
	return 0;
}
