#include <bits/stdc++.h>
#define X first
#define Y second

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


int n , m , T;
bool mark[Maxn] , isAns[Maxn];
vector <int> G[Maxn];
int color[Maxn] , cnt[Maxn] ;

void dfs(int v){
    mark[v] = 1;
    bool flag = 1;
    int counter = 1;
    for(int i = 0 ; i < G[v].size();i++){
        int u = G[v][i];
        //cerr << v << ":" << u << endl;
        if(!mark[u]){
            dfs(u);
            counter += cnt[u];
            if( color[v] != color[u] || !isAns[u]){
                flag = 0;
            }
        }
    }
    cnt[v] = counter;
    isAns[v] = flag;
    //cerr << v << ' ' << cnt[v] << ' ' << flag << endl;
}


int main() {
	ios::sync_with_stdio(0);

	cin >> T;
	while(T--){

        cin >> n ;
        for(int i = 0; i < n ; i++){
            cin >> color[i];
            G[i].clear();
        }
        for(int i = 0; i < n-1 ; i++){
            int t1,t2;
            cin >> t1 >> t2; t1--; t2--;
            G[t1].push_back(t2);
            G[t2].push_back(t1);
        }

        memset(mark,0,sizeof(mark));
        memset(isAns,0,sizeof(isAns));
        memset(cnt,0,sizeof(cnt));
        dfs(0);
        int ans = 0;
        for(int i = 0 ; i < n;i++){
            if(isAns[i]){
                ans = max(ans,cnt[i]);
            }
        }
        cout << ans << endl;

	}

}
