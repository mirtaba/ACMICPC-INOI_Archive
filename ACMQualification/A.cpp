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
	int t,n,d1,d2,d;
	vector<int> times;
	double time;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n >> d1 >> d2;
	    times.clear();
        for(int j = 0;j < n; j++){
            cin >> d >> time;
            if(d >= d1 && d <= d2){
                times.push_back((int)(time*20));
            }
        }
        sort(times.begin(),times.end());
        int ss = 0;
        int ans = 0;
        for(int j = 0; j < times.size(); j++){
            if(ss+times[j] > (8*20)) break;
            else{
                ss += times[j];
                ans++;
            }
        }
        cout << ans;
	}
	return 0;
}
