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

//ofstream fout ("11413.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn];

bool sim(int d, int n){
    bool ret = true;
    for(int i = 1; i <= n ; i++){

        int dif = in[i] - in[i-1];
        if(dif > d){
            ret = false;
        }
        if(dif == d){
            d--;
        }


    }
    //cerr << d << ' ' << ret << endl;
    return ret;
}


int main() {
	ios::sync_with_stdio(0);
	int n,m,T;
	cin >> T;
	for(int tt = 0; tt < T ; tt++){
        cin >> n ;
        int maxi = 0 ;
        in[0] = 0;
        for(int i = 1 ; i <= n ; i ++){
            cin >> in[i];
            maxi = max(maxi,in[i] - in[i-1]);
        }
        cout << "Case " << tt+1 << ": ";
        if(sim(maxi,n)){
            cout << maxi << endl;
        }
        else{
            cout << maxi + 1 << endl;
        }
	}
}
