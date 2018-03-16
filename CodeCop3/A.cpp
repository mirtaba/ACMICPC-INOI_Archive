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

int c , r;

int main() {
	ios::sync_with_stdio(0);
	cin >> r >> c;
	int a = 10 - r + 1;
	int b = (c>10) ? (20-c+1) : c;
	string s  = (c>10) ? "Left" : "Right";
	cout << s << " " << a << " " << b << endl;
}
