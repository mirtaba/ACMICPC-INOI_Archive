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

int main() {
	ios::sync_with_stdio(0);




	int n , k , a ,b;
	cin >> n >> k >> a >> b;

	int t = max(a,b) + k-1;
	if(t/k > min(a,b)+1){
        cout << "NO" << endl;
        return 0;
	}

	char aa = ((a > b) ? ('G') : ('B'));
	char bb = ((a > b) ? ('B') : ('G'));

	if(a < b) swap(a,b);

	int aaa = a;
	int bbb = b;

	int m = (a+k-1)/k;
	if(m == 1){
        for(int j = 0 ; j < k && aaa; j++){
            cout << aa;
            aaa--;
        }

        for(int j = 0 ; j < k && bbb; j++){
            cout << bb;
            bbb--;
        }
        for( int i = 0 ; i < aaa; i++){
            cout << aa;
        }
        cout << endl;
        return 0;

	}
    //cerr << m << endl;
    int aNum = (a + m - 1)/(m);
    //cerr << aNum << endl;
    int bNum = (b + m - 2)/(m-1);
    //cerr << bNum << endl;
	for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < aNum && aaa; j++){
            cout << aa;
            aaa--;
        }

        for(int j = 0 ; j < bNum && bbb; j++){
            cout << bb;
            bbb--;
        }
	}
	if(aaa){
        for( int i = 0 ; i < aaa; i++){
            cout << aa;
        }
	}
	cout << endl;








}
