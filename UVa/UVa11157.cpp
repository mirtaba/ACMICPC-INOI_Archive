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

int maxFinder(vector <int> rocks){

    int sizei = rocks.size();
    int ret = max(rocks[1]-rocks[0] , rocks[sizei-1]-rocks[sizei-2] );
    //cerr << ret << endl;
    //cerr << rocks[0] << ' ' << rocks[1];
    for(int i = 2 ; i < rocks.size();i++){
        //cerr << ' ' << rocks[i];
        ret = max(ret, rocks[i] - rocks[i-2]);
    }
    //cerr << endl;
    return ret;


}

int main() {
	ios::sync_with_stdio(0);
	int TT;
	cin >> TT;

	for(int T = 0 ; T < TT ; T++){
        int n , d;
        cin >> n >> d;

        int ans = 0;

        vector <int> rocks; // contain a big stone at start, a big at end and small are all in between
        rocks.push_back(0);

        for(int i = 0 ; i< n ; i++){

            char tmp , dum;
            int dis;
            cin >> tmp >> dum >> dis;
            if(tmp == 'S'){
                rocks.push_back(dis);
            }
            else{
                rocks.push_back(dis);
                ans = max(ans,maxFinder(rocks));
                rocks.clear();
                rocks.push_back(dis);
            }

        }

        rocks.push_back(d);
        ans = max(ans,maxFinder(rocks));


        cout << "Case " << T+1 <<  ": "  << ans << endl;
	}




}



