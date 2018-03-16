#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 * 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

vector <bool> mark (Maxn,false);
vector <int> edge(Maxn,-1);
vector <int> cycLenght;
int n;

void dfs(int v){
    if(!mark[v]){
        mark[v] = true;
        cycLenght[cycLenght.size()-1]++;
        dfs(edge[v]);
    }
    else{
        for(int i = v ; i < n; i++){
            if(!mark[i]){
                cycLenght.push_back(0);
                dfs(i);
                break;
            }
        }
    }
}

LL ans = 0;

int main() {
	ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        int tmp;
        cin >> tmp;
        edge[i] = tmp - 1;
    }
    cycLenght.push_back(0);
    dfs(0);
    sort(cycLenght.begin(),cycLenght.end());
    reverse(cycLenght.begin(),cycLenght.end());
    for(int i = 0 ; i < cycLenght.size() ; i++){
        //cerr << cycLenght[i] << endl;
        LL tmp = cycLenght[i];
        tmp *= tmp;
        ans += tmp;
        //cerr << ans << endl;
    }
    if(cycLenght.size()>1){
        LL tmp = cycLenght[0];
        tmp *= cycLenght[1];
        tmp *= 2;
        ans += tmp;
    }
    cout << ans << endl;
	return 0;
}
