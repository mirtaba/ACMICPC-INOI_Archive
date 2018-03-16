#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);
	unsigned int n , l , u;
	while(cin >> n >> l >> u){

        unsigned int tp = 0;


        for(int i = 31; i >= 0; i--){

            if(n & (1 << i)){
                unsigned int tmp = tp | ((1 << i)-1);
                if(tmp < l){
                    tp |= (1 << i);
                }

            }
            else{
                unsigned int tmp = tp | (1 << i);
                if(tmp <= u){
                    tp = tmp;
                }
            }
        }

        //cerr << "tp " << tp << endl;

        cout << tp << endl;





	}
}
