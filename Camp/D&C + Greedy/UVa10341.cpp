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

ofstream fout ("10341.out");
//ifstream fin ("greetings.in");

//#define cin fin
#define cout fout

double p,q,r,s,t,u;

double cal(double x ){

    double ret = p * exp(-x);
    ret += q * sin(x);
    ret += r * cos(x);
    ret += s * tan(x);
    ret += t * x * x;
    ret += u;
    return ret;
}


int main() {
	ios::sync_with_stdio(0);

	while(cin >> p >> q >> r >> s >> t >> u){
        double i = 0;
        double j = 1;
        double mid;
        while(i<j){
            //cerr << i << endl;
            mid = (i+j)/2.0;
            double tmp = cal(mid);
            //cerr << tmp << endl;
            if(abs(tmp) < EPS){
                break;
            }
            if(tmp > 0){
                i = mid;
            }
            else{
                j = mid;
            }

        }
        if(abs(cal(mid))<EPS){

            cout << setprecision(4) << fixed;
            cout << mid << endl;

        }
        else{
            cout << "No solution" << endl;
        }
	}
}
