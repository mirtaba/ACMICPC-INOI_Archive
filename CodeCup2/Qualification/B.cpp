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
	bool mark[Maxn];
	memset(mark,0,sizeof(mark));
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        if(s[0] == 's'){
            mark[0] = true;
        }
        else
        if(s[0] == 'j'){
            mark[6] = true;
        }
        else
            mark[s[0] - '0'] = true;
    }
        cin >> n;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        if(s[0] == 's'){
            mark[0] = true;
        }
        else
        if(s[0] == 'j'){
            mark[6] = true;
        }
        else
            mark[s[0] - '0'] = true;
    }
        cin >> n;
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        if(s[0] == 's'){
            mark[0] = true;
        }
        else
        if(s[0] == 'j'){
            mark[6] = true;
        }
        else
            mark[s[0] - '0'] = true;
    }

    int ans = 0;
    for(int i = 0 ; i < 7; i++){
        if(!mark[i]) ans++;
    }
    cout << ans << endl;


}
