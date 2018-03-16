#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;
typedef pair < PLL ,LL> node;
const int Maxn = 100*1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n , m , k;

int d[Maxn];
vector < node > Graph [Maxn]; // .X.X = node itself , .X.Y = weight , .Y = wisdomLimit
bool mark[Maxn];
set < PLL > S;

void Dijestra(int v, int wisLimit){
    for(int i = 0 ; i < n ; i ++){
        d[i] = abMax;
    }
    S.clear();
    memset(mark,false,sizeof(mark));
    d[v]=0;
    S.insert(make_pair(d[v],v));
    while(S.size())
    {
        int u=S.begin() -> second;
        //cerr << u << endl;
        mark[u]=true;
        S.erase({d[u],u});
        for (int i=0;i<Graph[u].size();i++)
        {
            int x=Graph[u][i].X.X;
            //cerr << x << endl;
            if( Graph[u][i].Y <= wisLimit && (d[x]>d[u]+Graph[u][i].X.Y && !mark[x]))
            {
                S.erase(make_pair(d[x],x));
                d[x]=d[u]+Graph[u][i].X.Y;
                S.insert(make_pair(d[x],x));
            }
        }
        //cerr << S.size() << endl;
    }
}

int t;

int main() {
	ios::sync_with_stdio(0);
	cin >> t;
	while (t--){
        cin >> n >> m >> k;
        for(int i = 0 ; i < n ; i++){
            Graph[i].clear();
        }
        for(int i = 0 ; i < m ; i++){
            int t1,t2,t3,t4;
            cin >> t1 >> t2 >> t3 >> t4;
            t1--; t2--;
            Graph[t1].push_back({{t2,t3},t4});
            Graph[t2].push_back({{t1,t3},t4});
        }

        int le = 1;
        int ri = Mod;
        int mid = (le + ri) / 2;
        Dijestra(0,mid);

        while(ri-le > 1){
            if(d[n-1] >= k){
                le = mid;
            }
            else{
                ri = mid;
            }
            mid = (le + ri) / 2;
            Dijestra(0,mid);
        }
        Dijestra(0,le);
        if(d[n-1] < k){
            cout << le << endl;
        }
        else{
            Dijestra(0,ri);
            if(d[n-1] < k){
                cout << ri << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
	}
}
