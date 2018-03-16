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

string in;
double d = 0, sum = 0 , fac;
int t;

int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
        cin >> in;

        sum = 0;
        d = 0;
        fac = 1;
        for(int i = 2 ; i <= in.size() ; i ++){
            fac *= i ;
        }
        fac = 1 / fac;
        //char
        while(next_permutation(in.begin(),in.end())){
            d = (1+ sum) * fac;
            sum += d;
        }
        cout << fixed << setprecision(9) << d << endl;
	}

}
