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
	LL n , k , m , x, y;
	cin >> n >> k >> m >> x >> y;
	set <LL> s;
	LL tmp = m;
	for(int i =0 ; i < n;i++){
        //cerr << tmp << endl;
        if(s.size()<k){
            s.insert(-tmp);
        }
        else{
            LL h = *(s.begin());
            if(h<(-tmp)){
                s.erase(s.begin());
                s.insert(-tmp);
            }
        }

        tmp = (x * tmp)%Mod + y;
        tmp %= Mod;

	}
	LL h = *(s.begin());
	cout << -h << endl;

}
