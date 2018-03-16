#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 200 * 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n;
LL in[Maxn];
multiset <LL> mults;
LL ans = 0;


int main() {
	ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0 ; i < n ; i ++){
        cin >> in[i];
        mults.insert(in[i]);
    }
    if(n%2==0) mults.insert(0);
    while(mults.size()>1){
        LL tp1 , tp2 , tp3;
        tp1 = *mults.begin();
        mults.erase(mults.begin());
        tp2 = *mults.begin();
        mults.erase(mults.begin());
        tp3 = *mults.begin();
        mults.erase(mults.begin());
        LL tmp = tp1+tp2+tp3;
        ans+= tmp;
        mults.insert(tmp);
    }
    cout << ans << endl;
	return 0;
}
