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

int d[Maxn][Maxn] , in[Maxn][Maxn];
string path[Maxn][Maxn];

int main() {

	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n ; i++){

        for(int j = 0 ; j < m;j++){

            cin >> in[i][j] ;
            if(j == 0){
                d[i][j] = in[i][j];
                s[i][j] = to_string(in[i][j]);
            }
            else{
                d[i][j] = abMax;
            }
        }
	}
    for(int i = 0; i < n ; i++){

        for(int j = 1 ; j < m;j++){

            for(int t = -1; t < 2; t++){

                int tp = (t + i + n)%n;

                if(d[i][j] == d[tp][j-1]){

                }
            }
        }
	}



}
