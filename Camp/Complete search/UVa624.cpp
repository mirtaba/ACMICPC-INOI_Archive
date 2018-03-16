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


#define bitAt(a,b) (a & (1<<b))


//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int main() {
	ios::sync_with_stdio(0);
	int n,t;
	while(cin >> n >> t){
        vector <int> in;
        for(int i = 0 ; i < t ;  i++){
            int tmp;
            cin >> tmp;
            in.push_back(tmp);
        }
        int ans = 0 , ansMask = 0 , ansCnt = 0;
        for(int i = 0 ; i < (1 << t) ; i++){
            int sum = 0 , cnt = 0;
            for(int j = 0 ; j < t ; j++){

                if(bitAt(i,j)){
                    sum+= in[j];
                    cnt++;
                }
            }

            if(sum > ans && sum <= n){
                ans = sum;
                ansMask = i;
                ansCnt = cnt;
            }
            else
            if(sum == ans && ansCnt < cnt){
                ansMask = i;
                ansCnt = cnt;
            }

        }
        for(int j = 0 ; j < t ; j++){

                if(bitAt(ansMask,j)){
                    cout << in[j] << ' ';
                }
        }
        cout << "sum:" << ans << endl;

	}
}

