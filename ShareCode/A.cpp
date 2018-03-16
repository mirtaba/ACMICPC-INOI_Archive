#include<iostream>
#include<cmath>

#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-6;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


int main() {
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while(T--){
        LL sum = 0;
        int n;
        cin >> n;
        LL maxi=-200 , mini=200 ;
        for(int i = 0 ; i < n ;i++){

            LL tmp;
            cin >> tmp;
            maxi = max(maxi,tmp);
            mini = min(mini,tmp);
            sum += tmp;

        }
        if(n==1 || n == 2){
            cout << "YES" << endl;
        }
        else{

            double avr = (double)sum/n;
            //cerr << avr << endl;
            double avr2 = (double)(maxi+mini)/2;
            //cerr << avr2 << endl;
            if(abs(avr-avr2)<(1+EPS) || ){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }

        }
	}

}
