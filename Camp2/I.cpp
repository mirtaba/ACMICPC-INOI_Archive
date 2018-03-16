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

vector <int> g[Maxn];
bool mark[Maxn];
int main() {

	ios::sync_with_stdio(0);


    int n , m;
	cin >> n >> m;
	for( int i = 0 ; i < m ; i ++){
        int t1 , t2;
        cin >> t1 >> t2;
        t1--;
        t2--;
        g[t1].pb(t2);
        g[t2].pb(t1);
	}
	PII ans = {Mod,1552521};
	for(int i = 0 ; i < n ; i++){
	    if(ans.X > ((int)g[i].size() + 1)){
            ans.X = ((int)g[i].size() + 1);
            ans.Y = i;
        }
	}
	memset(mark,0,sizeof(mark));
	for(int i = 0 ; i < g[ans.Y].size(); i++){
        mark[g[ans.Y][i]] = true;
	}
	mark[ans.Y] = true;

	for(int i = 0 ; i < n ; i++){
        cout << !mark[i] << ' ';
	}
	cout << endl;







}
