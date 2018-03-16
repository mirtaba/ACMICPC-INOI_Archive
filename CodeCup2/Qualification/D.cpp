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
	int n,x=0,y=0;
	cin >> n >> x >> y;

    int tp = n,xx=0 ,yy=0;
	while(tp>0){
        if(tp%y == 0){
            cout << xx << ' ' << tp/y << endl;
            return 0;
        }
        xx++;
        tp -= x;
	}
	if(tp == 0){
        cout << xx << ' ' << 0 << endl;
	}
	else
	cout << -1 << endl;
}

