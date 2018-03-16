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

vector <PII> dish;



int main() {
	ios::sync_with_stdio(0);
	int N,x,T,K;
	while (cin >> N >> x >> T >> K ){

        for(int i = 0 ; i < K; i++){
            int tmp = 0;
            int price = 0;
            cin >> price;
            for(int j = 0 ; j < N+1; j++){
                int tmp2 = 0;
                cin >> tmp2;
                tmp += tmp2;
            }
            dish.push_back({price , tmp});
        }


	}
}
