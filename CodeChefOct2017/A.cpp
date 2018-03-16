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

int t;

int main() {
	ios::sync_with_stdio(0);
	cin >> t;

	while(t-- > 0){
        int n , p;
        cin >> n >> p;
        int easy = 0 , hard = 0;
        int halfP = p / 2;
        int tenthP = p / 10;

        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            if(tmp <= tenthP) hard++;
            if(tmp >= halfP) easy++;
        }
        cerr << easy << ' ' << hard << endl;
        if( hard == 2 && easy == 1){
            cout << "yes" << endl;

        }
        else{
            cout << "no" << endl;
        }

	}

}
