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
	char ch;
	int tp;
	cin >> ch >> tp;
	tp--;
	int tmp = ch - 'a';
	bool flag1 = 0 , flag2 = 0;
	if(tmp == 0 || tmp == 7){
        flag1 = 1;
	}
    if(tp == 0 || tp == 7){
        flag2 = 1;
	}
	if(flag1 && flag2){
        cout << 3 << endl;
        return 0;
	}
    if(flag1 || flag2){
        cout << 5 << endl;
        return 0;
	}
	cout << 8 << endl;
	return 0;
}
