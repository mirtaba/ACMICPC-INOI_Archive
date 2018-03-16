#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 5000 + 2;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n , k , a[Maxn] , sum[Maxn] , d[Maxn][Maxn]; // i is the number of moves used to get at place j
int dp[2][Maxn][Maxn];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        tmp+= 5000;
        a[tmp] = 1;
	}

	for (int i = 5000 ; i >= 0 ; i--){
        sum [i] = sum[i + 1] + a[i];
	}
	for (int i = 5000 ; i <= 10000 ; i++){
        sum [i] = sum[i - 1] + a[i];
	}

    d[0][5000] = 1;
	for (int i = 1 ; i <= k ; i++){
        for(int j = 5000-i ; j <= 5000+i ; j++){
            int tmp = (j-1) < 0 ? 0 : d[i-1][j-1];
            d[i][j] = (tmp + d[i-1][j+1])%Mod;
        }
	}
	dp[0][5000][5000] = 1;
    for (int i = 1 ; i <= k ; i++){
        for(int j = 5000-i ; j <= 5000 ; j++){
            for(int t = 5000 ; t <= 5000+i ;t++){
                dp[(i%2)?0:1][j][t] = (2 * dp[((i-1)%2)?0:1][j-1][t-1] + d[i-1][j-1] + d[i-1][t-1])%Mod;
            }
        }
	}

	int ans = 0;
    for(int j = 5000-k ; j <= 5000 ; j++){
        for(int t = 5000 ; t <= 5000+k ;t++){
            ans += (dp[(k%2)?0:1][j][t] * (sum[j]+sum[t])%Mod)%Mod;
        }
    }
    cout << ans << endl;

}
