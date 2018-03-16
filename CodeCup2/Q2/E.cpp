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

int d[Maxn];

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
    int tp = 0;
	for(int i = 0 ; i < n ; i++){
        char tmp;
        cin >> tmp;
        if(tmp == 'W'){
            tp--;
        }
        else{
            tp++;
        }
        d[i] = tp;
	}
	if(n == 1){
        cout << '=' << endl;
	}
	else{
        double ans = 0;
        for(int i = n-2; i >=0;i--){
            ans *=2;
            ans += d[i];
        }
        if(ans > 0){
            cout << 'S' << endl;
        }
        else{
            cout << 'W' << endl;
        }
	}
}
