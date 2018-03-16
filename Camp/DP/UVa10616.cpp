#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 2 * 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("10616.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


LL D[Maxn][25][25][15]; //numbers that crafted :) ,sum reminder to d, nubmers of selected numbers
LL in[Maxn];

LL cnt(LL i , LL rem , LL d , LL m){
    //cerr << i << ' ' << rem << ' ' << d << ' ' << m << endl;
    if(i < 0) return(0);
    if(m == 0) {
        //cerr << "as" << (rem == 0) << endl;
        return( rem == 0 );
    }

    if(D[i][rem][d][m] > -1) {
        //cerr << D[i][rem][d][m] << endl;
        return D[i][rem][d][m];
    }

    if( i+1 == m){
        LL tmp = 0;
        for(int j = 0 ; j <= i ; j++ ){
            tmp += (in[j]%d+d)%d;
            tmp %= d;
        }
        if(tmp == rem ){
            //cerr <<  "as" << 2 << endl;
            D[i][rem][d][m] = 1;
            return (1);
        }
    }

    LL ret = cnt(i-1 , (rem+d-(in[i]%d))%d , d , m-1) + cnt(i-1, rem , d ,  m);
    D[i][rem][d][m] = ret;
    //cerr <<  ret << endl;
    return ret;

}



int main() {

	ios::sync_with_stdio(0);
    LL n , q ,T = 0;
    while(cin >> n >> q , n , q){

        memset( D, -1, sizeof(D) );
        for(int i = 0; i < n ; i++){
            cin >> in[i];
        }

        cout << "SET " << ++T << ":" << endl;

        for(int i = 0; i < q ; i++){

            int D , M;
            cin >> D >> M;
            cout << "QUERY " << i+1 << ": " << cnt(n-1,0,D,M) << endl;

        }

    }

}
