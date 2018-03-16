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

int table[Maxn][Maxn];

int main() {

	ios::sync_with_stdio(0);

    cin >> n >> m >> k;
    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < m ; j++){
            char ch;
            cin >> ch;
            table[i][j] = (ch == '.')?(0):(1);
        }

    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            switch(table[i][j])
            case(0):
                cout << '.';
                break;
            case(1):
                cout << '#';
                break;
            case(2):
                cout << 'X';
                break;
        }
    }




}
