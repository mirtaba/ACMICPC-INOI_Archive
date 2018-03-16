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
	string s;
	cin >> s;
	int st = -1,en = -1;
	for(int i = 0; i < s.size();i++){

        if(st == -1 && s[i] != 'a'){
            st = i;
        }
        if( (st != -1 && en == -1) && s[i] == 'a'){
            en = i;
        }
	}

	if(st == -1) { s[s.size()-1] = 'z'; cout << s << endl; return 0;}

	if(en == -1) en = s.size();

    //cerr << st << ' ' << en << endl;
	for(int i = st; i < en; i++){
       // cerr << s[i] << endl;
        s[i] = (((s[i] - 'a') - 1 + ('z' - 'a' + 1)) % ('z' - 'a' + 1)) + 'a';
       // cerr << s[i] << endl;

	}
	cout << s << endl;
}
