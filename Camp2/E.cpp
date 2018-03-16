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

vector <PLL> start , fin ;
vector <LL> poi;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	int a1 = 0 , a2 = 0;
	for(int i = 0 ; i < n ;i++){
        LL t1,t2;
        cin >> t1 >> t2;
        start.pb({t1,i});
        fin.pb({t2,i});
        poi.pb(t1);
        poi.pb(t2);
        if(a2 < t2){
            a2 = t2;
            a1 = t1;
        }
        else{
            if(a2 == t2 && a1 < t1){
                a1 = t1;
            }
        }
	}
	sort(start.begin(),start.end());
	sort(fin.begin(),fin.end());
	sort(poi.begin(),poi.end());
	auto t = unique(poi.begin(),poi.end());
	poi.resize(t - poi.begin());
    start.pb({Mod,n});
	fin.pb({Mod,n});
	int j = 0;
	int p = 0;
	set <LL> s;
	s.clear();
	LL ans = 0;
	for(int i = 0 ; i < poi.size() ; i++){

        while(poi[i] == start[j].X){
            s.insert(start[j].Y);
            j++;
        }
        if(poi[i]>= a1)
            ans = max(ans,(LL)s.size());
        while(poi[i] == fin[p].X){
            s.erase(fin[p].Y);
            p++;
        }
	}
	cout << ans << endl;
}

