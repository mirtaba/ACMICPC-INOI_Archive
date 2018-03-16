#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
LL a[Maxn],d[Maxn][Maxn] , cost[Maxn][Maxn];
int main() {
	ios::sync_with_stdio(0);
	LL n,k;
	cin >> n>> k;
    for(int i=0;i<k;i++){
        cin >> a[i];
        d[i][i] = a[i];
        cost[i][i] = 0;
    }

    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            d[i][j] = d[i][j-1] + a[j];
        }
    }

    LL sum = 0;
    for(int i=1;i<k;i++){
        for(int j=0;i+j<k;j++){
            LL mini = d[j][j] + d[j+1][j+i] + cost[j][j] + cost[j+1][j+i];
            for(int t = j;t<i+j;t++){
                mini = min(mini, d[j][t] + d[t+1][j+i] + cost[j][t] + cost[t+1][j+i]);
                //cerr << j << ' ' << i+j << ' ' << t <<  ' ' << mini << endl;
            }
            cost[j][i+j] = mini;
        }
    }
    cout << cost[0][k-1] << endl;
}

