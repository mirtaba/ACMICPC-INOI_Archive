#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout
LL a[Maxn];

vector < LL > d[Maxn] ;//(Maxn, vector <LL> (Maxn,0));
int main() {
	ios::sync_with_stdio(0);
    LL n, m;
    cin >> n >> m;
    a[0] = 0;
    for(int i = 1 ; i < n+1 ;i++){
        cin >> a[i];
    }
    for(int i = 0 ; i < m ;i++){
        int l , r , k;
        cin >> l >> r >> k;
        if(k < (n/10000)){
        if(d[k].size()== 0){
            d[k].push_back(0);
            for(int j = 1 ; j  <k+1; j++){
                d[k].push_back(a[j]);
            }
            for(int j = k+1; j < n+1;j++){
                d[k].push_back(d[k][j-k]+a[j]);
            }
        }
            /**
            int start = l%k;
            if(!start) start = k;

            if(!d[start][k]){
                d[start][k]= a[start];
                //cerr << start << ' ' << k << " : " << d[start][k] << ' ';
                for(int j = start+k ; j <n+1; j+=k){
                    d[j][k] += d[j-k][k] + a[j];
                    //cerr << d[j][k] << ' ';
                }
                //cerr << endl;
            }
            /**/
            if(l > k)
                cout << d[k][r] - d[k][l-k] << endl;
            else
                cout << d[k][r] << endl;
        }
        else{
            LL ans = 0;
            for(int j = l ; j < r+1;j+=k){
                ans += a[j];
            }
            cout << ans << endl;
        }
    }
}

