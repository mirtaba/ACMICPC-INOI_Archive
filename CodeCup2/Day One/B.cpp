#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <LL, LL> PII;

const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

LL n;
vector <LL> G[Maxn];
LL dist[Maxn];

PII BFS(LL x){

    PII ans = {-1,-1};
    bool mark[Maxn];
    memset(mark,0,sizeof(mark));
    queue <LL> q;
    q.push(x);
    dist[x] = 0;
    mark[x] = true;

    while(q.size()){
        LL u = q.front();
        q.pop();
        for(int i = 0 ; i<G[u].size();i++){
            LL v = G[u][i];
            if(!mark[v]){
                mark[v] = true;
                dist[v] = dist[u] + 1;

                if(dist[v] > ans.Y){
                    ans = {v,dist[v]};
                }

                q.push(v);
            }
        }
    }

    return ans;
}



int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0 ; i < n-1 ; i++){
        LL tmp1 , tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        G[tmp1].push_back(tmp2);
        G[tmp2].push_back(tmp1);
	}
	PII fl = BFS(1);
	PII y = BFS(fl.X);

	LL ans = n * (n-1);
	ans /= 2;

	cout << y.Y << ' ' << ans << endl;



}

