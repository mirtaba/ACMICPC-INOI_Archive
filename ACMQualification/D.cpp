#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI  = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n;
vector<PII> p;
int main() {
	ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        p.clear();
        int u,v;
        for(int i=0;i<n;i++){
            cin >> u >> v;
            p.push_back({u,v});
        }

        sort(p.begin(),p.end());
        vector<PII> minx;
        vector<PII> maxx;
        for(int i=0;i<p.size();i++){
            if(p[i].X == p[0].X){
                minx.push_back({p[i].X,p[i].Y});
            }
            if(p[i].X == p[p.size()-1].X){
                maxx.push_back({p[i].X,p[i].Y});
            }
        }
        cerr << minx[0].X << ' ' << minx[0].Y << endl <<maxx[0].X << ' ' << maxx[0].Y << endl;
        sort(minx.begin(),minx.end());
        sort(maxx.begin(),maxx.end());

        PII p1 = minx[0];
        PII p2 = maxx[maxx.size()-1];

        int dis = abs(p1.X - p2.X) + abs(p1.Y - p2.Y);
        double ans = (double)sqrt(dis);
        cout << setprecision(4) << fixed << ans << endl;
    }

}
