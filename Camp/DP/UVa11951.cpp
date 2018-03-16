#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long int LL;
typedef pair <int, int> PII;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("11951.out");
//ifstream fin ("11951.in");

//#define cin fin
//#define cout fout

LL T , n , m ,w , in[Maxn][Maxn];

int main() {
	ios::sync_with_stdio(0);
	memset(in,0,sizeof(in));
	cin >> T;
	for(int ttt = 1; ttt <= T; ttt++){

        cin >> n >> m >> w;

        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= m ; j++){

                LL tmp;
                cin >> tmp;

                tmp += in[i-1][j];
                tmp += in[i][j-1];

                tmp -= in[i-1][j-1];

                in[i][j] = tmp;

            }
        }

        LL ansArea = 0 , ansPrice = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m ; j++){
                for(int ii = 1; ii <= i ; ii++){
                    for(int jj = 1; jj <= j; jj++){

                        LL tmp = in[i][j];

                        tmp -= in[ii-1][j];
                        tmp -= in[i][jj-1];

                        tmp += in[ii-1][jj-1];

                        LL area = (i-ii+1) * (j-jj+1);

                        if(area > ansArea && tmp <= w){
                            ansArea = area;
                            ansPrice = tmp;
                        }
                        else
                        if(area == ansArea && ansPrice > tmp){
                            ansPrice = tmp;

                        }
                        //cerr << ansPrice << endl;

                    }

                }

            }
        }
        cout << "Case #" << ttt << ": " << ansArea << " " << ansPrice << endl;
	}
}
