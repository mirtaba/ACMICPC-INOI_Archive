#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL, LL> PLL;

const int Maxn = 100*100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout


vector <PLL> g[Maxn];
int n , m , dist[Maxn];
bool mark[Maxn];

int main() {
	ios::sync_with_stdio(0);

	cin >> n >> m;
	for(int i = 0 ; i < n ; i++){
        dist[i] = abMax;
	}


	for(int i = 0 ; i< m ;i++){
        int tmp1,tmp2 , tpc;
        cin >> tmp1 >> tmp2 >> tpc;
        tmp1--; tmp2--;
        g[tmp1].push_back({tpc,tmp2});
        g[tmp2].push_back({tpc,tmp1});
	}

	set<PLL> s;
	s.clear();
	s.insert({0,0});
	int ans = 0;
	while(s.size()){
        PLL u = *s.begin();
        //cerr << u.Y+1 << ' ' << ans << endl;
        s.erase(s.begin());
        if(mark[u.Y]) continue;
        mark[u.Y] = true;
        ans += u.X;
        for(int i = 0 ; i < g[u.Y].size(); i++){
            PLL v = g[u.Y][i];
            if(!mark[v.Y] && dist[v.Y] > v.X){
                s.erase({dist[v.Y],v.X});
                dist[v.Y] = v.X;
                s.insert(v);
            }
        }
	}
	cout << ans << endl;
}
