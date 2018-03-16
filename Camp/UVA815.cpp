#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100*1000 + 250;
const int abMax = 1 << 29 ;

ofstream fout ("815.out");
//ifstream fin ("greetings.in");

//#define cin fin
#define cout fout

int main() {
	ios::sync_with_stdio(0);
	int n ,m , in[Maxn] ,T = 0;
	double water;
	while(cin >> n >> m , n, m ) {
        for(int i = 0; i < n * m; i++) {

            cin >> in[i];
        }
        in[m*n] = abMax;
        sort(in, in + (m * n));
        cin >> water;
        water /= 100.00d;

        double ansHight = 0;
        int ansCount = 0;

        for(int i = 0; i <= (n * m); i++) {
            //cerr <<water << ' ' << in[i] << endl;
            LL tmp = ((i+1)*(LL)(in[i+1] - in[i]));
            //cerr << tmp << endl;
            if( tmp <= water ) {

                water -= tmp;
            }
            else {
                //cerr << in[i] << endl;

                ansCount = i+1;
                ansHight = in[i];
                ansHight += water/ansCount;
                water = 0;
                break;
            }

        }
        double ansPersent;
        //cerr << water << endl;
        if(water == 0)
            ansPersent = 100 * ((double)ansCount/(n*m));
        else {
            ansPersent = 100.00;
            ansHight = in[n*m - 1];
            ansHight +=  (double)water/(n*m);
        }
        cout << "Region " << ++T << endl;
        cout << setprecision(2) << fixed;
        cout << "Water level is " << ansHight << " meters." << endl;
        cout << ansPersent << " percent of the region is under water." << endl;
        cout << endl;
	}






}
