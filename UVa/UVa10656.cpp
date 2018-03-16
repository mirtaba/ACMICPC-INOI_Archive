 #include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

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

int main() {
	ios::sync_with_stdio(0);
	int n;
	vector <int> ans;
	while(cin >> n , n){
        ans.clear();
        for(int i = 0 ; i < n ; i++){

            int tmp;
            cin >> tmp;
            if(tmp > 0)
                ans.push_back(tmp);
            }


        if(ans.size() == 0){
            cout << 0 << endl;
            continue;
        }
        cout << ans[0];
        for (int i = 1 ; i < ans.size(); i++){
                cout << ' ' << ans[i];

        }
        cout << endl;
    }


}
