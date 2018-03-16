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
	int n , m;
	while(cin >> n >> m){
        int mo [20];

        for(int i = 0 ; i < (1 << 12); i++){
            cerr << i << endl;
            int sumAns = 0;
            for(int j = 0 ; j < 2 ; j++){
                cerr << j << endl;
                if(bitAt(i,j)){
                    mo[i] = -m;
                    sumAns -=m;
                }
                else{
                    mo[i] = n;
                    sumAns +=n;
                }

            }
            cerr << sumAns << endl;
            bool flag =0;
            for(int j = 0 ; j <8 ; j++){
                int sum = 0;
                for(int t = 0 ; t < 5;t++){

                    sum+=mo[j+t];
                }
                if(sum>=0){
                    flag = 1;
                    break;
                }
            }

            if(!flag){
                if(sumAns >=0 )
                    cout << sumAns << endl;
                else{
                    cout << "Deficit"<< endl;
                }
                break;
            }

        }

	}
}
