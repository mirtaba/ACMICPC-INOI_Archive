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

#define bitAt(a,b) (a & (1<<b))

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout



int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
        bool flag = 1;
        int n , p;

        cin >> n;
        cin >> p;
        vector <int> bar;
        for(int i = 0 ; i < p; i++){
            int tmp;
            cin >> tmp;
            bar.push_back(tmp);

        }
        for(int i = 0 ; i < (1 << p); i++){
            int sum = 0;
            for(int j = 0 ; j < p ; j++){

                if(bitAt(i,j)){
                    sum+= bar[j];
                }
            }
            if(sum == n){
                cout << "YES" << endl;
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "NO" << endl;
        }
	}
}
