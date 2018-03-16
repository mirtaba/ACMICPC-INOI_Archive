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


string s[Maxn];
int n ;

int main() {
	ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i];
    }
    for(int i = 0 ; i < n-1; i++){
        cout << s[i] << " to " << s[i+1] << ": ke ba in dar agar dar bande dar manand, dar manand." << endl;
        for(int j = i+1; j >= 1; j--){
            cout << s[j] << " to " << s[j-1] << ": dar manand?" << endl;
        }
        for(int j = 0; j<=i;j++){
            cout << s[j] << " to " << s[j+1] << ": dar manand." << endl;
        }
    }
}
