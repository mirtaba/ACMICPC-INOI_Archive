#include <bits/stdc++.h>
#define X first
#define Y second

#define pb push_back

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

int t , n , d;
vector < LL > test;

int main() {
	ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        test.clear();
        test.pb(1-n);
        while(test[test.size()-1] > -1001){
            test.pb(test[test.size()-1] * n);
        }
        reverse(test.begin(),test.end());
        bool winner = 1;
        for(int i = 0 ; i < n ; i++){
            cin >> d;
            auto p = upper_bound(test.begin(),test.end(),-d);
            int index = test.end() - p;
            //cerr << index << endl;
            if(index %2 == 1)
                winner = 0;
        }
        if(winner){
            cout << "Bob" << endl;
        }
        else{
            cout << "Alice" << endl;
        }
    }
}

