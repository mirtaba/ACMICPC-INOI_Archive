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

vector <int> ans;
int n , m , T;
bool mark[Maxn];
vector <int> G[Maxn];

int cnt;

void backtrack(int x){

    if(x == n){

        if(ans.size()<cnt){
            ans.clear();
            for(int i = 0 ; i < n ; i++){

                if(mark[i]){

                    ans.push_back(i);

                }
            }
        }

    }
    else{
        bool flag = false;
        for(int i = 0;  i < G[x].size();i++){
            int u = G[x][i];
            if(mark[u] == 1){

                flag = true;

            }
        }
        if(flag){
            backtrack(x+1);
        }
        else{
            mark[x] = true;
            cnt++;
            backtrack(x+1);
            mark[x] = false;
            cnt--;
            backtrack(x+1);
        }
    }

}

int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	/**/
	while(T--){

        cin >> n >> m;
        for(int i = 0; i <= n ; i++){
            G[i].clear();
        }
        for(int i = 0; i < m ; i++){
            int t1,t2;
            cin >> t1 >> t2; t1--; t2--;
            G[t1].push_back(t2);
            G[t2].push_back(t1);
        }
        ans.clear();
        memset(mark,0,sizeof(mark));
        cnt = 0;
        backtrack(0);
        cout << ans.size() << endl;
        cout << ans[0]+1;
        for(int i = 1 ; i < ans.size();i++){
            cout << ' ' << ans[i]+1;
        }
        cout << endl;

	}
	/**/
}
