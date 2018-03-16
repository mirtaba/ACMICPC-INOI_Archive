#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 100 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int n;
string orig , s;
bool mark[Maxn][Maxn];

int main() {
	ios::sync_with_stdio(0);
    cin >> n >> orig;
    for(int i = 0 ; i < n ; i++){
        cin >> s;
        bool isValid = true;
        for(int j = 0 ; j < s.size(); j++){
            bool flag = false;
            for(int t = 0 ; t < orig.size() ; t++){
                if(s[j] == orig[t]){
                    mark[i][t] = true;
                    flag = true;
                }
            }
            if(!flag) isValid = false;
        }
        for(int t = 0 ; t < orig.size() ; t++){
            if(!mark[i][t])
                isValid = false;
        }
        if(isValid){
                cout << "Yes" << endl;
        }
        else{
                cout << "No" << endl;
        }
    }

}
