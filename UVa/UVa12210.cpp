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
	int n , m , T = 0;
	while(cin >> n >> m , n , m){

        vector <int> boys, girls;

        for(int i = 0 ; i < n ; i++){

            int tmp;
            cin >> tmp;
            boys.push_back(tmp);

        }
        sort(boys.begin(),boys.end());

        for(int i = 0 ; i < m ; i++){

            int tmp;
            cin >> tmp;
            girls.push_back(tmp);

        }


        cout << "Case " << ++T << ": ";
        if(n > m){
            cout << n-m << ' ' << boys[0] << endl;
        }
        else{
            cout << 0 << endl;
        }




	}
}
