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
int n , m , in[Maxn][Maxn];
vector <int> diameter[Maxn];
int main() {
	ios::sync_with_stdio(0);

	while (cin >> n >> m , n ,m){

        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){

                cin >> in[i][j] ;

            }
        }
        for(int t = -n + 1; t < m;t++){
            diameter[t+n-1].clear();

            for(int i = 0 ; i < n;i++){
                int j = i + t;
                if(j >= 0 && j<m){

                    diameter[t+n-1].push_back(in[i][j]);
                    //cerr << in[i][j] << endl;
                }
            }
            //cerr << endl;
        }
        int test;
        cin >> test;
        for(int itp = 0; itp < test; itp++){
            int low,high , ans = 0;
            cin >> low >> high;
            for(int t = 0; t < n+m-1; t++){
                int dis = upper_bound(diameter[t].begin(),diameter[t].end(),high)-lower_bound(diameter[t].begin(),diameter[t].end(),low);
                ans = max(ans,dis);
            }
            cout << ans << endl;

        }
        cout << '-' << endl;

	}

}
