#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("11553.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int T , n , in[Maxn][Maxn];


int main() {

	ios::sync_with_stdio(0);

	cin >> T;
	while(T--){

        cin >> n;
        vector <int> col ;
        for(int i = 0 ; i < n;i++){
            col.push_back(i);

            for(int j = 0 ; j < n;j++){
                cin >> in[i][j];
            }
        }

        int ans = abMax;

        do{


                int tmp = 0;
                for(int i = 0 ; i < n;i++){
                    tmp += in[i][col[i]];
                }
                //cerr << tmp << endl;
                ans = min(tmp,ans);





        }while(next_permutation(col.begin(),col.end()));




        cout << ans << endl;


	}


}
