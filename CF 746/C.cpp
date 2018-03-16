#include <bits/stdc++.h>
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
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {

	ios::sync_with_stdio(0);

	int s, xs , xf;
	cin >> s >> xs >> xf;
	int st , si;
	cin >> st >> si;
	int start , d;
	cin >> start >> d;
    start *= d;
    st *= d;
    si *= d;
    xs *= d;
    xf *= d;
    s *= d;

    int dis = 0;
    if(xs < xf){

        if(start > xf){
            dis = 2 * abs(s);
            dis -= abs(start - xf);
        }
        else{
            if(start < xs){
                dis = abs(start - xf);
            }
            else{
                dis = 2 * abs(s);
                dis += abs(start - xf);
            }
        }
    }
    else{

        if(start < xf){
            dis = 2 * abs(s);
            dis -= abs(xf) + abs(start);
        }
        else{
            if(start > xs){
                dis = 2 * abs(s);
                dis -= abs(xf) + abs(start);
            }
            else{

           }
        }
    }
    //cerr << dis << endl;
    int tt = dis*st;
    int ti = abs(xs-xf) * si;
    cout << min(tt , ti) << endl;





}
