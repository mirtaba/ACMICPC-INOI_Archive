#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 3*100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn],n;


int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int a = abMax;
	int b = -abMax;
	for(int i = 0; i < n ; i++){

        cin >> in[i];

	}
	sort(in,in+n);

    cout << in[(n-1)/2] << endl;




}
