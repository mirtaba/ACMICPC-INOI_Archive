#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("10755.in");

//#define cin fin
//#define cout fout

LL in[Maxn][Maxn][Maxn];

int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;

	while(T--){
	    memset(in,0,sizeof(in));
        int a,b,c;
        cin >> a >> b >> c;

        for(int i = 1; i < a+1;i++){
            for(int j = 1 ; j < b+1; j++){
                for(int t = 1; t < c+1; t++){

                    LL tmp;
                    cin >> tmp;

                    tmp += in[i-1][j][t];
                    tmp += in[i][j-1][t];
                    tmp += in[i][j][t-1];

                    tmp -= in[i-1][j-1][t];
                    tmp -= in[i-1][j][t-1];
                    tmp -= in[i][j-1][t-1];

                    tmp += in[i-1][j-1][t-1];

                    in[i][j][t] = tmp;
                }
            }
        }
        LL ans = in[1][1][1];

        for(int i = 1; i < a+1;i++){
            for(int j = 1 ; j < b+1; j++){
                for(int t = 1; t < c+1; t++){

                    for(int ii = 1; ii <= i ; ii++){
                        for(int jj = 1 ; jj <= j ; jj++){
                            for(int tt = 1; tt <= t; tt++){

                                LL tmp = in[i][j][t];

                                tmp -= in[ii-1][j][t];
                                tmp -= in[i][jj-1][t];
                                tmp -= in[i][j][tt-1];

                                tmp += in[ii-1][jj-1][t];
                                tmp += in[ii-1][j][tt-1];
                                tmp += in[i][jj-1][tt-1];

                                tmp -= in[ii-1][jj-1][tt-1];

                                ans = max(ans,tmp);

                                //cerr << ans << endl;
                            }
                        }
                    }
                }
            }
        }

        cout << ans << endl;
        if(T){
            cout << endl;
        }

	}
}
