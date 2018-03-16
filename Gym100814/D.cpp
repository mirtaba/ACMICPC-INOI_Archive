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

int t , n ,q;

vector < PLL > g [Maxn];

LL d[Maxn];

vector <LL> leafs;

void dfs (int u){

    if(g[u].size() > 0){
        int mini = g[u][0].X;

        for(int i = 0 ; i < g[u].size();i++){
            int v = g[u][i].Y;
            d[v] = d[u] + mini + (g[u][i].X - mini) * 2;
            dfs(v);
        }
    }
    else{
        leafs.push_back(d[u]);
    }

}


int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
        memset(d , 0 , sizeof(d));
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            g[i].clear();
        }
        leafs.clear();

        for(int i= 1 ; i < n ; i++){
            LL par , w;
            cin >> par >> w;
            par--;
            g[par].push_back({w,i});
        }

        for(int i = 0 ; i < n ; i++){
            sort(g[i].begin() , g[i].end());
        }

        dfs(0);

        sort(leafs.begin(), leafs.end());

        cin >> q;
        for(int i = 0 ; i < q ; i++){
            LL tmp;
            cin >> tmp;

            auto p = upper_bound(leafs.begin(),leafs.end(),tmp);

            cout << p - leafs.begin() << endl;
        }


	}
}
