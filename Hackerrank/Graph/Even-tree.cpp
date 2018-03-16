#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 29 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n , m;
vector <int> g[Maxn];
int mark[Maxn] , childNum[Maxn] , markCut[Maxn], ans = 0;

void dfs(int v){

    mark[v] = 1;
    int kid = 0;
    for(int i = 0 ; i<g[v].size(); i++){

        int u = g[v][i];
        if(!mark[u]){
            dfs(u);
            kid+= (childNum[u]+1);
        }

    }
    childNum[v] = kid ;

}


void cut(int v){

    markCut[v] = 1;
    for(int i = 0 ; i<g[v].size(); i++){
        int u = g[v][i];
        if(!markCut[u]){
            cut(u);
            if(childNum[u]%2 == 1){
                ans++;
            }
        }

    }

}




int main() {
	ios::sync_with_stdio(0);

	cin >> n >> m;

	for(int i = 0 ; i<m;i++){
        int tpv1 , tpv2;
        cin >> tpv1 >> tpv2;
        tpv1--; tpv2--;
        g[tpv1].push_back(tpv2);
        g[tpv2].push_back(tpv1);
	}
    dfs(0);
    cut(0);
    cout << ans << endl;







}
