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

//ofstream fout ("11236.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);
	for(LL i = 1 ; i <= 2000;i++){
        if((i*i*i*i)>= 2000 * 1000 * 1000) break;
        //cerr << i << endl;
        for(LL j = i ; j <= 2000 - i ; j++){

            if((i*j*j*j)>=2000 * 1000 * 1000) break;

            for(LL t = j ; t <= (2000 - (i+j)); t++){

                if((i*j*t*t)>=2000 * 1000 * 1000) break;

                LL face = 1000 * 1000 * (i+j+t);
                LL bot = (i*j*t) - (1000 * 1000);
                if(bot == 0) continue;
                //cerr << face << ' ' << bot << endl;
                if(face%bot == 0){
                    LL p = face/bot;
                    //cerr << i << ' ' << j << ' ' << t << ' ' << p << endl;
                    if(p>=t && (i+j+t+p)<=2000 ){

                        LL sum = (i+j+t+p);
                        sum *= 1000 * 1000;
                        LL mul = i*j*t*p;
                        if(mul == sum){

                            long double I = i/100.00;
                            long double J = j/100.00;
                            long double T = t/100.00;
                            long double P = p/100.00;

                            cout << setprecision(2) << fixed;
                            cout << I << ' ';
                            cout << J << ' ';
                            cout << T << ' ';
                            cout << P << endl;

                        }

                    }
                }
            }
        }
	}
}
