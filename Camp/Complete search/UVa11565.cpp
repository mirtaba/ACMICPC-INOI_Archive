#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

ofstream fout ("11565.out");
//ifstream fin ("greetings.in");

//#define cin fin
#define cout fout


int A,B,C;

int main() {

	ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--){
        cin >> A >> B >> C;
        bool ansNotFound = 1;

        for(int i = -80 ; i < min(110,A) && ansNotFound ; i++){

            for(int j = i+1; j < min(110,A-i) && ansNotFound; j++){

                int k = A -(i+j);
                if(k <= j) continue;

                int sum = i+j+k;
                int mul = i*j*k;
                int powSum = i*i + j*j + k*k;
                if((sum == A && mul == B) && powSum == C){

                    cout << i << ' ' << j << ' ' << k << endl;
                    ansNotFound = 0;
                }

            }
        }
        if(ansNotFound){
            cout << "No solution." << endl;
        }

    }
}
