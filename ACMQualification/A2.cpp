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

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	int n,d1,d2;
    while(t--){
        cin >> n >> d1 >> d2;
        vector<double> ans;
        int dif;
        double tim;
        for(int i=0;i<n;i++){
            cin >> dif >> tim;
            if(dif <= d2 && dif>=d1){
                ans.push_back(tim);
            }
        }
        sort(ans.begin(),ans.end());
        double sum = 0;
        int cnt = 0;
        for(int i=0;i<ans.size();i++){
            sum += ans[i];
            if(sum <= 8){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}
