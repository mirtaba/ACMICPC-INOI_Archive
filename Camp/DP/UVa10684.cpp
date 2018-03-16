#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 10*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL d[Maxn] , in[Maxn] , n;

int main() {
	ios::sync_with_stdio(0);
	int n;
	while(cin >> n , n){

        for(int i = 0; i < n;i++){
            cin >> in[i];
        }
        d[0] = max(in[0],(LL)0);
        LL ans = d[0];
        //cerr << ans << endl;
        for(int i = 1;i<n;i++){
            if(d[i-1] + in[i] > 0){
                d[i] = d[i-1] + in[i];
            }
            else{
                d[i] = 0;
            }
            //cerr << d[i] << endl;
            ans = max(ans,d[i]);
        }
        if(ans>0){
            cout << "The maximum winning streak is " << ans << '.' << endl;
        }
        else{
            cout << "Losing streak." << endl;
        }

	}
}
