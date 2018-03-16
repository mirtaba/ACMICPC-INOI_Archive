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
    LL d[Maxn][Maxn/100] , a[Maxn];
    int main() {
        ios::sync_with_stdio(0);
        LL n, m;
        memset(d,0,sizeof(d));
        cin >> n >> m;
        a[0] = 0;
        for(int i = 1 ; i < n+1 ;i++){
            cin >> a[i];
        }
        for(int i = 0 ; i < m ;i++){
            int l , r , k;
            cin >> l >> r >> k;
            if(k<(Maxn/100)){
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
                if(l > k)
                    cout << d[r][k] - d[l-k][k] << endl;
                else
                    cout << d[r][k] << endl;
            }
            else{

                LL ans = 0;
                for(int j = l ; j < r+1; j+=k){
                    ans += a[j];
                }
                cout << ans << endl;
            }
        }
    }
