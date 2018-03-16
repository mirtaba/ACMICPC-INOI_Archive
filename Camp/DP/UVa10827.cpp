#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn][Maxn] , sum[Maxn][Maxn], n , T;


int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--){

        memset(in,0,sizeof(in));
        memset(sum,0,sizeof(sum));

        cin >> n;
        for(int i = 1; i <= n ; i++){
            for(int j = 1; j <= n; j++){

                int tmp;
                cin >> tmp;

                for(int tx = 0 ; tx < 2 ; tx++){
                    for(int ty = 0; ty < 2 ; ty++){

                        in[i+(tx*n)][j+(ty*n)] = tmp;

                    }
                }


            }
        }

        for(int i = 1; i <= 2*n ; i++){
            for(int j = 1; j <= 2*n; j++){

                int tmp = 0;

                tmp += in[i][j];

                tmp += sum[i-1][j];
                tmp += sum[i][j-1];

                tmp -= sum[i-1][j-1];

                sum[i][j] = tmp;
                //cerr << sum[i][j] << ' ';
            }
            //cerr << endl;
        }

        int ans = in[1][1];

        for(int i = 1; i <= 2*n ; i++){
            for(int j = 1; j <= 2*n; j++){

                for(int ii = max(i-n+1,1); ii <= i ; ii++){
                    for(int jj = max(j-n+1,1) ; jj <= j ; jj++){

                        int tmp = sum[i][j];

                        tmp -= sum[ii-1][j];
                        tmp -= sum[i][jj-1];

                        tmp += sum[ii-1][jj-1];

                        ans = max(ans,tmp);
                    }
                }
            }
        }

        cout << ans << endl;

	}
}
