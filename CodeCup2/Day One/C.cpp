#include <bits/stdc++.h>
#define X first
#define Y second

#define bitAt(a,b) (a & (1<<b))

using namespace std;

typedef long long LL;
typedef pair <int, int> PII;
typedef pair <LL,LL> PLL;

const int Maxn = 1000 + 250;
const int Mod = 1000 * 1000 * 1000 + 7;
const int abMax = 1 << 30 ;
const double EPS = 1e-9;
const double PI = acos(-1.0);

//ofstream fout ("greetings.out");
//ifstream fin ("greetings.in");

//#define cin fin
//#define cout fout

int in[Maxn][Maxn];
int maxi[Maxn];

int main() {
	ios::sync_with_stdio(0);
	memset(maxi,0,sizeof(maxi));
	int n , m;
	cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m ; j++){
            char tp;
            cin >> tp;
            switch (tp){
            case '#':
                in[i][j] = 0;
                break;
            case 's':
                in[i][j] = 1;
                break;
            case 'n':
                in[i][j] = 2;
                break;
            case 't':
                in[i][j] = 3;
                break;
            }
        }
    }
    int b[10];
    memset(b,0,sizeof(b));
    cin >> b[1] >> b[2] >> b[3];
    bool flag = true;
    int maxi2[Maxn];
    memset(maxi2,0,sizeof(maxi2));
    for(int i = n-1 ; i >=0 ; i--){
        for(int j = 0 ; j< m ; j++){
            if(in[i][j] != 0){
                if(maxi2[j] == 0){
                    maxi2[j] = in[i][j];
                }
                else{
                    if(maxi2[j] > in[i][j]){
                        flag = false;
                    }
                }

            }
        }
    }

    if(!flag){
        cout << "Let's go to the park" << endl;
        return 0;
    }

    for(int i = n-1 ; i >=0 ; i--){
        for(int j = 0 ; j< m ; j++){
            if(in[i][j] != 0){
                maxi[j] = max(maxi[j],in[i][j]);

            }
            else{

                for(int t = 0 ; t < 3;t++){
                    if(b[maxi[j]+t] > 0){
                        b[maxi[j]+t]--;
                        in[i][j] = maxi[j]+t;
                        maxi[j] = maxi[j]+t;
                        break;
                    }
                }
            }
        }
    }
    int tt = b[1] + b[2] + b[3];
    if(tt > 0 || !flag){
        cout << "Let's go to the park" << endl;
        return 0;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m ; j++){
            switch (in[i][j]){
            case 0:
                cout << '#';
                break;
            case 1:
                cout << 's';
                break;
            case 2:
                cout << 'n';
                break;
            case 3:
                cout << 't';
                break;
            }
        }
        cout << endl;
    }
    return 0;



}
