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

vector <int> in;

bool iterat(){
    if(in[0] == in[in.size()-1]){
        return false;
    }
    int tmp = in[in.size()-1] - in[0];
    in[0] = tmp;
    in[in.size()-1] = tmp;
    sort(in.begin(),in.end());
    return true;
}
int T ,n;

int main() {
	ios::sync_with_stdio(0);
	cin >> T;
	while(T--){
        in.clear();
        cin >> n;
        for(int i = 0 ; i < n ; i++){
            int tmp;
            cin >> tmp;
            in.push_back(tmp);
        }
        sort(in.begin(),in.end());
        while(iterat()){

        }
        cout << in[0] << endl;

	}
}
