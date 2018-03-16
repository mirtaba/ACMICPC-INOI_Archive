#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
int in[Maxn][Maxn],n;

int main() {
	ios::sync_with_stdio(0);
    memset(in,0,sizeof(in));
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ; j++){

            int tmp;
            cin >> tmp;

            tmp += in[i-1][j];
            tmp += in[i][j-1];

            tmp -= in[i-1][j-1];

            in[i][j] = tmp;
        }
    }

    int ans = in[1][1];

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ; j++){

            for(int ii = 1; ii <= i ; ii++){
                for(int jj = 1; jj <= j; jj++){

                    int tmp = in[i][j];

                    tmp -= in[ii-1][j];
                    tmp -= in[i][jj-1];

                    tmp += in[ii-1][jj-1];

                    ans = max(tmp,ans);

                }

            }

        }
    }

    cout << ans << endl;


}
